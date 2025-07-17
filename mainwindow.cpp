#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow (QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_warehouseManager = new WarehouseManager(this);

    ui->partsTableView->setModel(m_warehouseManager);

    m_warehouseManager->addPart(Part("Śruba M5", "SC-8815",150, 0.25));
    m_warehouseManager->addPart(Part("Nakrętka M5", "NT-8816", 200, 0.15));
    m_warehouseManager->addPart(Part("Podkładka", "PD-9021", 300, 0.05));
}

MainWindow::~MainWindow(){

    delete ui;
}
