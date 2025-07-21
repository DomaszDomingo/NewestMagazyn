#include "editpartdialog.h"
#include "ui_editpartdialog.h"

EditPartDialog::EditPartDialog(const Part & partToEdit, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditPartDialog)
{
    ui->setupUi(this);

    ui->nameLineEdit->setText(partToEdit.name());
    ui->catalogNumberLineEdit->setText(partToEdit.catalogNumber());
    ui->quantitySpinBox->setValue(partToEdit.quantity());
    ui->priceDoubleSpinBox->setValue(partToEdit.price());
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
    int quantity = ui->quantitySpinBox->value();
    double price = ui->priceDoubleSpinBox->value();

    QString aisle = ui->aisleLineEdit->text();
    int rack = ui->rackSpinBox->value();
    int shelf = ui->shelfSpinBox->value();
    Location location (aisle, rack, shelf);

    //pobieranie danych z pól
    Part updatedPart (name, catalogNumber, quantity, price, location);
    updatedPart.setId(m_partId);
    return updatedPart;
}

