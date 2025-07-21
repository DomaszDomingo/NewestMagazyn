#include "addpartdialog.h"
#include "ui_addpartdialog.h"

addPartDialog::addPartDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addPartDialog)
{
    ui->setupUi(this);
}

addPartDialog::~addPartDialog()
{
    delete ui;
}

Part addPartDialog::getPartData() const
{
    QString name = ui->nameLineEdit->text();
    QString catalogNumber = ui->catalogNumberLineEdit->text();
    int quantity = ui->quantitySpinBox->value();
    double price = ui->priceDoubleSpinBox->value();

    QString aisle = ui->aisleLineEdit->text();
    int rack = ui->rackSpinBox->value();
    int shelf = ui->shelfSpinBox->value();
    Location location (aisle,rack,shelf);

    return Part (name, catalogNumber, quantity, price, location);
}
