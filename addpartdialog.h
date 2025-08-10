#ifndef ADDPARTDIALOG_H
#define ADDPARTDIALOG_H

#include <QDialog>
#include "part.h"
#include "location.h"

namespace Ui {
class addPartDialog;
}

class addPartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addPartDialog(const QList<Location> &availableLocations, QWidget *parent = nullptr);
    ~addPartDialog();

    Part getPartData() const;
private:
    Ui::addPartDialog *ui;
    QList<Location> m_locations;
};

#endif // ADDPARTDIALOG_H
