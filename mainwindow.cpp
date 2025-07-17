#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "addpartdialog.h"

MainWindow::MainWindow (QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_dbManager()
{
    ui->setupUi(this);

    m_warehouseManager = new WarehouseManager(this);
    ui->partsTableView->setModel(m_warehouseManager);

    // W konstruktorze MainWindow
    // m_warehouseManager->addPart(Part("Śruba M5", "SC-8815", 150, 0.25, Location("A", 1, 3)));
    // m_warehouseManager->addPart(Part("Nakrętka M5", "NT-8816", 200, 0.15, Location("A", 1, 4)));
    // m_warehouseManager->addPart(Part("Podkładka", "PD-9021", 300, 0.05, Location("B", 2, 11)));
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
    }
}
