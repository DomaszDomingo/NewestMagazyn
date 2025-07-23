#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "addpartdialog.h"
#include "editpartdialog.h"
#include "issuepartdialog.h"

MainWindow::MainWindow (QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_dbManager()
{
    ui->setupUi(this);

    setWindowTitle("Magazinierix2000");
    m_warehouseManager = new WarehouseManager(m_dbManager, this);
    ui->partsTableView->setModel(m_warehouseManager);
    ui->partsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->partsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    m_chart = new QChart();
    m_series = new QLineSeries();
    m_chart->addSeries(m_series);

    auto *axisX = new QDateTimeAxis;
    axisX->setTickCount(5);
    axisX->setFormat("dd.MM.yy HH:mm");
    axisX->setTitleText("Data zmiany");
    m_chart->addAxis(axisX, Qt::AlignBottom);
    m_series->attachAxis(axisX);

    auto *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Ilość");
    m_chart->addAxis(axisY, Qt::AlignLeft);
    m_series->attachAxis(axisY);

    m_chart->legend()->hide();
    ui->quantityChartView->setChart(m_chart);
    ui->quantityChartView->setRenderHint(QPainter::Antialiasing);

    connect (ui->partsTableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this,&MainWindow::onPartSelectionChanged);

}

MainWindow::~MainWindow(){

    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    addPartDialog dialog (this);
    if (dialog.exec() != QDialog::Accepted){
        return; // użytkownik anulował
    }
    Part partFromDialog = dialog.getPartData();

    //sprawdz czy główny rekord dla tej czesci juz istnieje
    //jeśli nie, stworz go i pobierz jego id. Jeśli tak pobierz jego id
    int partId = m_dbManager.getOrCreatePart(partFromDialog);

    //dodaj nową partię do tabeli PartBatches używając ID

    m_dbManager.addBatch(partId, partFromDialog.quantity(),partFromDialog.price());


    m_warehouseManager->refreshData();
}

void MainWindow::on_editButton_clicked()
{
    const QModelIndex currentIndex = ui->partsTableView->selectionModel()->currentIndex();

    if (!currentIndex.isValid()){
        QMessageBox::warning(this, "Brak zaznaczenia" , "Proszę najpierw zaznaczyć część do edycji.");
        return;
    }

    Part partToEdit = m_warehouseManager->getPartAtIndex(currentIndex);

    EditPartDialog dialog (partToEdit,this);

    if(dialog.exec() == QDialog::Accepted){
        //Pobierz zaktualizowane dane
        Part updatedPart = dialog.getPartData();
        // zleć aktualizację modelu
        m_warehouseManager->updatePart(updatedPart);
        //zleć aktualizację w bazie danych
        m_dbManager.updatePart(updatedPart, "Edycja danych części");
    }
}

void MainWindow::on_deleteButton_clicked()
{
    //pobranie aktualnie zaznaczonego indeksu w tabeli
    const QModelIndex currentIndex = ui->partsTableView->selectionModel()->currentIndex();

    if (!currentIndex.isValid()){
        QMessageBox::warning(this, "Brak zaznaczenia", "Proszę najpierw zaznaczyć część do usunięcia");
        return;
    }
    //wyświetlenie okna dialogowego z potwierdzeniem
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Potwierdzenie usunięcia", "Czy na pewno chcesz usunąć wybrany rekord?",
        QMessageBox::Yes|QMessageBox::No);
    //jezeli tak
    if (reply == QMessageBox::Yes){
        Part partToDelete = m_warehouseManager->getPartAtIndex(currentIndex);

        //zlecenie usunięcia rekordu z bazy danych
        m_dbManager.deletePart(partToDelete.id());

        //zlecenie usunięcia wiersza z modelu(odświeża tabele)
        m_warehouseManager->deletePart(currentIndex.row());
    }
}

void MainWindow::onPartSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);
    if(selected.isEmpty() || !selected.first().isValid()){
        m_series->clear();
        m_chart->setTitle("Wybierz część, aby zobaczyć historię");
        return;
    }

    QModelIndex selectedIndex = selected.first().indexes().first();
    Part selectedPart = m_warehouseManager->getPartAtIndex(selectedIndex);

    QList<QPointF> history = m_dbManager.getQuantityHistoryForPart(selectedPart.id());

    m_series->replace(history);

    m_chart->setTitle("Historia ilości dla: " + selectedPart.name());

    if (!history.isEmpty()){
        QDateTime minDate = QDateTime::fromMSecsSinceEpoch(history.first().x());
        QDateTime maxDate = QDateTime::fromMSecsSinceEpoch(history.last().x());

        double minQty = history.first().y();
        double maxQty = history.first().y();

        for(const auto & point : history){
            if (point.y() < minQty) minQty = point.y();
            if (point.y() > maxQty) maxQty = point.y();
        }

        qobject_cast<QDateTimeAxis * > (m_chart->axes(Qt::Horizontal).first())->setRange(minDate,maxDate);
        auto * axisY = qobject_cast<QValueAxis*> (m_chart->axes(Qt::Vertical).first());
        axisY->setRange(minQty , maxQty);
        axisY->setTickCount(3);


            }
}

void MainWindow::on_issueButton_clicked()
{
    //Pobierz wszystkie części z modelu
    QList<Part> allParts = m_warehouseManager->getAllParts();
    if(allParts.isEmpty()){
        QMessageBox::information(this, "Brak mageriałów", "Magazyn jest pusty.");
        return;
    }

    //Otwarcie okna dialogowego i przekazanie listy części
    IssuePartDialog dialog (allParts, this);
    if(dialog.exec() != QDialog::Accepted){
        return; //anulowano
    }

    //Pobranie z dialogu (ID Cześci i ilość)
    auto issueDataOpt = dialog.getIssueData();
    if (!issueDataOpt.has_value()){
        return; // nie udało się pobrać danych
    }

    IssueData data = *issueDataOpt;

    QString mode = ui->issueModeComboBox->currentText();
    bool success = false;

    if(mode == "FIFO"){
        success = m_dbManager.issuePartFIFO(data.partId,data.quantity);
    } else { // LIFO
        success = m_dbManager.issuePartLIFO(data.partId,data.quantity);
    }

    if (success){
        QMessageBox::information(this, "Sukces", "Materiał został wydany pomyślnie");
    } else {
        QMessageBox::warning(this, "Błąd", "Wydanie materiału nie powiodło się. Sprawdź czy na stanie jest wystarczająca ilość");
    }

    m_warehouseManager->refreshData();

}

void MainWindow::on_historyButton_clicked()
{
//Sprawdzenie czy coś jest zaznaczone
    const QModelIndex currentIndex = ui->partsTableView->selectionModel()->currentIndex();

    if (!currentIndex.isValid()){
        QMessageBox::warning(this, "Brak zaznaczenia" , "Proszę najpierw zaznaczyć część, aby zobaczyc historię." );
        return;
    }
    Part selectedPart = m_warehouseManager->getPartAtIndex(currentIndex);
    //Pobranie szegółowej historii z bazy danych
    QList<HistoryEntry> history = m_dbManager.getDetailedHistoryForPart(selectedPart.id());

    if (history.isEmpty()){
        QMessageBox::information(this, "Brak historii" , "Brak zapisanej historii dla tej części.");
        return;
    }

    //UtwóRz i wyświetl okno dialogowe

    HistoryDialog dialog (selectedPart.name(),history,this);
    dialog.exec();

}













































