#ifndef ADDLOCATIONDIALOG_H
#define ADDLOCATIONDIALOG_H

#include <QDialog>
#include "location.h"
#include "ui_addlocationdialog.h"

namespace Ui{

class AddLocationDialog;
}

class AddLocationDialog : public QDialog
{
    Q_OBJECT

public:

    explicit AddLocationDialog(QWidget * parent = nullptr);

    explicit AddLocationDialog(const Location & locationToEdit,
                               QWidget * parent = nullptr);

    ~AddLocationDialog();

    Location getLocationData() const;

private:
    Ui::AddLocationDialog *ui;
    int m_locationId = - 1; //do przechowywania ID edytowalnej lokalizacji

};

#endif // ADDLOCATIONDIALOG_H
