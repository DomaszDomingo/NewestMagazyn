#ifndef ADDPARTDIALOG_H
#define ADDPARTDIALOG_H

#include <QDialog>
#include "part.h"

namespace Ui {
class addPartDialog;
}

class addPartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addPartDialog(QWidget *parent = nullptr);
    ~addPartDialog();

    Part getPartData() const;

private:
    Ui::addPartDialog *ui;
};

#endif // ADDPARTDIALOG_H
