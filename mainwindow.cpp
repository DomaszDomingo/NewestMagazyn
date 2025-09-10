#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "addpartdialog.h"
#include "editpartdialog.h"
#include "issuepartdialog.h"
#include "addlocationdialog.h"
#include "receivestockoperation.h"
#include "issuestockoperation.h"
#include <memory>


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

    m_locationManager = new LocationManager (m_dbManager, this);
    ui->locationsTableView->setModel(m_locationManager);
    ui->locationsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->locationsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

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

    addPartDialog dialog(m_dbManager.getAllLocations(), this);
    if (dialog.exec() == QDialog::Accepted) {
        Part partData = dialog.getPartData();

        WarehouseOperation* operation = nullptr;                                                        //klasyczny mechanizm polimofrizmu.

        operation = new ReceiveStockOperation(partData);

        if (operation->execute(m_dbManager)) {
            QMessageBox::information(this, "Sukces", "Nowy materiał został dodany.");

            m_warehouseManager->refreshData();

        } else {
            QMessageBox::warning(this, "Błąd", "Nie udało się dodać materiału.");
        }

        delete operation;

    }
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
    QList<Part> allParts = m_warehouseManager->getAllParts();
    if (allParts.isEmpty()) {
        QMessageBox::information(this, "Brak materiałów", "Magazyn jest pusty.");
        return;
    }

    // 1. Otwórz dialog, aby zapytać o część i ilość (bez strategii)
    IssuePartDialog dialog(allParts, this);
    if (dialog.exec() != QDialog::Accepted) {
        return; // Anulowano
    }

    auto issueDataOpt = dialog.getIssueData();
    if (issueDataOpt.has_value()) {
        const auto& issueData = issueDataOpt.value();
        Part partToIssue = m_warehouseManager->getPartById(issueData.partId);

        // 2. Odczytaj strategię z ComboBox w głównym oknie
        IssueStockOperation::IssueStrategy strategy;
        QString selectedMode = ui->issueModeComboBox->currentText();

        if (selectedMode == "LIFO") {
            strategy = IssueStockOperation::IssueStrategy::LIFO;
        } else { // Domyślnie lub gdy wybrano "FIFO"
            strategy = IssueStockOperation::IssueStrategy::FIFO;
        }


        auto operation = std::make_shared<IssueStockOperation>(                                     //pod operation alokowany jest inteligentny wskaźnik
                                                                                                    //make_shared przygotowało ten wskaźnik z IssueStockOperation
                                                                                                    //dzięki temu ze jest zastosowane auto to operation ma typ
                                                                                                    //std::shared_ptr<IssueStockOperation>
            partToIssue,
            issueData.quantity,
            partToIssue.name(),
            strategy
            );


        if (operation->execute(m_dbManager)) {                                                      //operation wykorzystuje metodę execute, która jest metodą wirtualną
                                                                                                    //w klasie bazowej WarehouseOperation
            QMessageBox::information(this, "Sukces", "Wydano towar z magazynu.");
            m_warehouseManager->refreshData();
        } else {
            QMessageBox::warning(this, "Błąd", "Wydanie materiału nie powiodło się. Sprawdź, czy na stanie jest wystarczająca ilość.");
        }
    }
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

void MainWindow::on_addLocationButton_clicked()
{
    AddLocationDialog dialog (this);
    if (dialog.exec() == QDialog::Accepted){
        Location newLocation = dialog.getLocationData();
        if(m_dbManager.addLocation(newLocation)){
            m_locationManager->refreshData();
        } else {
            QMessageBox::warning(this, "Błąd", "Nie udało się dodać lokalizacji. Sprawdź, czy taka lokalizacja już nie istnieje");

        }
    }
}

void MainWindow::on_editLocationButton_clicked()
{
    const QModelIndex currentIndex = ui->locationsTableView->selectionModel()->currentIndex();
    if(!currentIndex.isValid()){
        QMessageBox::warning(this, "Brak zaznaczenia" , "Proszę zaznaczyć lokalizację do edycji");
        return;
    }

    Location locationToEdit = m_locationManager->getLocationAtIndex(currentIndex);

    AddLocationDialog dialog (locationToEdit, this);
    if(dialog.exec() == QDialog::Accepted){
        Location updatedLocation = dialog.getLocationData();
        if(m_dbManager.updateLocation(updatedLocation)){
            m_locationManager->refreshData();
        } else {
            QMessageBox::warning(this, "Błąd", "Nie udało się zaktualizować lokalizacji.");
        }
    }
}

void MainWindow::on_deleteLocationButton_clicked()
{
    const QModelIndex currentIndex = ui->locationsTableView->selectionModel()->currentIndex();

    if(!currentIndex.isValid()){
        QMessageBox::warning(this,"Brak zaznaczenia","Proszę najpierw zaznaczyć element do usunięcia");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Potwierdzenie usunięcia",
                                  "Czy na pewno usunąć wybraną lokalizację?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes){
        //Pobierz pełny obiekt lokalizacji z modelu
        Location locationToDelete = m_locationManager->getLocationAtIndex(currentIndex);

        if(m_dbManager.deleteLocation(locationToDelete.id())){
                //jeśli usunięcie się powiodło, odświez  widok tabeli
            m_locationManager->refreshData();
            QMessageBox::information(this, "Sukces", "Lokalizacja została usunięta.");
        } else {
            QStringList blockingParts = m_dbManager.getPartNamesAtLocation(locationToDelete);
            QString blockingPartsString = blockingParts.join(", ");
            QMessageBox::warning(this, "Operacja nieudana",
                                 "Nie można usunąć lokalizacji, ponieważ jest ona w użyciu. "
                                 "Upewnij się, że żaden materiał nie jest do niej przypisany.");
        }
    }

}













































