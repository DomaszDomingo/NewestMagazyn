#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "warehousemanager.h"
#include "databasemanager.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    WarehouseManager *m_warehouseManager;
    DatabaseManager m_dbManager;                            //obiekt ktory jest polem klasy MainWindow



private slots:
    void on_addButton_clicked();                           //slot ktory po kliknieciu przycisku Dodaj otworzy okno dodawania materiału

};
#endif // MAINWINDOW_H
