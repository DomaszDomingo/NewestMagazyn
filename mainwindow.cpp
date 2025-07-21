#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "addpartdialog.h"
#include "editpartdialog.h"

MainWindow::MainWindow (QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_dbManager()
{
    ui->setupUi(this);

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
        return; // Użytkownik anulował. Wyjście z funkcji
    }

    Part partFromDialog = dialog.getPartData();
    auto existingPartOpt = m_dbManager.getPartByCatalogNumber(partFromDialog.catalogNumber());

    if (existingPartOpt.has_value()){
        // część istnieje. Zaktualizuj w bazie
        Part existingPart = *existingPartOpt;
        existingPart.setQuantity(existingPart.quantity() + partFromDialog.quantity());
        m_dbManager.updatePart(existingPart);
        QMessageBox::information(this, "Aktualizacja ilości", "Materiał o takim numerze katalogowym istnieje. Zaktualizowano ilość");

    } else {
        //część nie istnieje dodaj do bazy
        m_dbManager.addPart(partFromDialog);
    }

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
        m_dbManager.updatePart(updatedPart);
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
        qobject_cast<QValueAxis * > (m_chart->axes(Qt::Vertical).first())->setRange(minQty - 1, maxQty +1);
    }
}
