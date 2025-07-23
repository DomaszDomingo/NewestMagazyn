#include "editpartdialog.h"
#include "ui_editpartdialog.h"

EditPartDialog::EditPartDialog(const Part & partToEdit, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditPartDialog)
{
    ui->setupUi(this);

    ui->nameLineEdit->setText(partToEdit.name());
    ui->catalogNumberLineEdit->setText(partToEdit.catalogNumber());
    const Location & loc = partToEdit.location();
    ui->aisleLineEdit->setText(loc.aisle());
    ui->rackSpinBox->setValue(loc.rack());
    ui->shelfSpinBox->setValue(loc.shelf());

    m_partId = partToEdit.id();
}

EditPartDialog::~EditPartDialog()
{
    delete ui;
}

Part EditPartDialog::getPartData() const
{
    QString name = ui->nameLineEdit->text();
    QString catalogNumber = ui->catalogNumberLineEdit->text();

    QString aisle = ui->aisleLineEdit->text();
    int rack = ui->rackSpinBox->value();
    int shelf = ui->shelfSpinBox->value();
    Location location (aisle, rack, shelf);

    //pobieranie danych z pól
    Part updatedPart (name, catalogNumber, 0,0.0, location);
    updatedPart.setId(m_partId);
    return updatedPart;
}

