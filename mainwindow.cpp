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


}

MainWindow::~MainWindow(){

    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    addPartDialog dialog (this);

    if (dialog.exec() == QDialog::Accepted){
        Part newPart = dialog.getPartData();

        m_warehouseManager->addPart(newPart);

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
