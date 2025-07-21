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
        QMessageBox::information(this, "Aktualizacja ilości", "Materiał o takin numerze katalogowym istnieje. Zaktualizowano ilość");

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
