#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "addpartdialog.h"

MainWindow::MainWindow (QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_dbManager()                                         //konstruktor DatabaseManager zostanie wywołany automatycznie
{
    ui->setupUi(this);

    m_warehouseManager = new WarehouseManager(this);
    ui->partsTableView->setModel(m_warehouseManager);


}

MainWindow::~MainWindow(){

    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    //tworzenie instancji okna dialogowego dla okna tworzenia części
    addPartDialog dialog (this);

    //Wyświetlenie okna i oczekiwanie na reakcję użytkownika na kliknięcie przycisku OK lub Anuluj
    //exec() blokuje wykonanie kodu az do zamknięcia okna
    if (dialog.exec() == QDialog::Accepted){
        //Po kliknęciu przycisku OK, nastepuje pobranie danych z okna
        Part newPart = dialog.getPartData();

        m_warehouseManager->addPart(newPart);
    }
}
