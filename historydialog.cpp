#include "historydialog.h"
#include "ui_historydialog.h"
#include <QTableWidgetItem>

HistoryDialog::HistoryDialog (const QString & partName, const QList<HistoryEntry> & history, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HistoryDialog)
{
    ui->setupUi(this);

    setWindowTitle("Historia dla: " + partName);
    connect(ui->closeButton, &QPushButton::clicked, this, &QDialog::reject);
    //Ustawienie i wypelnienie tabeli
    setupTable(history);
}

HistoryDialog::~HistoryDialog()
{
    delete ui;
}

void HistoryDialog::setupTable(const QList<HistoryEntry> &history)
{
    ui->historyTableWidget->setColumnCount(3);
    ui->historyTableWidget->setHorizontalHeaderLabels({"Data","Operacja", "Ilość po zmianie"});
    ui->historyTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //blokada edycji
    ui->historyTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    // wypełnienie danymi
    ui->historyTableWidget->setRowCount(history.count());
    for (int row = 0; row < history.count(); ++row){
        const auto & entry = history.at (row);

        //Tworzenie komórek tabeli
        auto *dateItem = new QTableWidgetItem(entry.date.toString("dd.MM.yyyy HH:mm:ss"));
        auto *descItem = new QTableWidgetItem(entry.description);
        auto *quantityItem = new QTableWidgetItem(QString::number((entry.quantityAfterChange)));

        //wyśrodkowanie
        dateItem->setTextAlignment(Qt::AlignCenter);
        quantityItem->setTextAlignment(Qt::AlignCenter);

        //dodanie komórek do tabeli
        ui->historyTableWidget->setItem(row, 0 , dateItem);
        ui->historyTableWidget->setItem(row, 1, descItem);
        ui->historyTableWidget->setItem(row, 2, quantityItem);
        //dostosowanie wysokości wierszy do wypełnionej tabeli
        ui->historyTableWidget->resizeRowsToContents();


    }
}
