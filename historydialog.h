#ifndef HISTORYDIALOG_H
#define HISTORYDIALOG_H

#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class HistoryDialog;
}

class HistoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryDialog(const QString & partName, const QList<HistoryEntry> & history, QWidget *parent = nullptr);
    ~HistoryDialog();

private:
    void setupTable (const QList <HistoryEntry> & history);
    Ui::HistoryDialog *ui;
};

#endif // HISTORYDIALOG_H
