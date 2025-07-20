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

    if (dialog.exec() == QDialog::Accepted){
        Part newPart = dialog.getPartData();
        Part partFromDialog = dialog.getPartData();

        //sprawdz czy część o tym numerze katalogowym istnieje
        auto existingPartOpt = m_dbManager.getPartByCatalogNumber(partFromDialog.catalogNumber());

        if (existingPartOpt.has_value()){
            //część istnieje - zaktualizuj ilość
            Part existingPart = *existingPartOpt; //rozpakuj obiekt z optional
            int newQuantity = existingPart.quantity() + partFromDialog.quantity();
            existingPart.setQuantity(newQuantity);

            //zlec aktualizacje w bazie danych
            m_dbManager.updatePart(existingPart);

            QMessageBox::information(this,"Aktualizacja ilości", QString("Część '%1' juz istniała w bazie. Jej ilość została zaktualizowana do %2 szt.")
                                         .arg(existingPart.name()).arg(newQuantity));
        } else {

            //Częśc nie istnieje - dodaj nowy rekord
            m_dbManager.addPart(partFromDialog);
        }

        //odświez model zeby pokazac zmiany

        m_warehouseManager->addPart(partFromDialog);

        m_dbManager.addPart(newPart);

        m_warehouseManager->addPart(newPart);
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
