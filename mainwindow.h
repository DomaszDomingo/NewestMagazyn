#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "warehousemanager.h"
#include "databasemanager.h"
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QItemSelection>
#include "historydialog.h"
#include "locationmanager.h"


//QT_CHARTS_USE_NAMESPACE

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
    databaseManager m_dbManager;
    QChart *m_chart;
    QLineSeries *m_series;
    LocationManager *m_locationManager;


private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void onPartSelectionChanged(const QItemSelection & selected, const QItemSelection &deselected);
    void on_issueButton_clicked();
    void on_historyButton_clicked();
    void on_addLocationButton_clicked();
    void on_editLocationButton_clicked();
    void on_deleteLocationButton_clicked();

};
#endif // MAINWINDOW_H
