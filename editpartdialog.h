#ifndef EDITPARTDIALOG_H
#define EDITPARTDIALOG_H

#include <QDialog>
#include "part.h"

namespace Ui {
class EditPartDialog;
}

class EditPartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditPartDialog(const Part & partToEdit, QWidget *parent = nullptr);
    ~EditPartDialog();
    Part getPartData() const;

private:
    Ui::EditPartDialog *ui;
    int m_partId;
};

#endif // EDITPARTDIALOG_H
