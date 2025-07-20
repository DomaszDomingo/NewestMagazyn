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
    ui->locationLineEdit->setText(partToEdit.location().toString());

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

    QStringList locationParts = ui->locationLineEdit->text().split('-');
    Location location;
    if (locationParts.count() == 3) {
        location.setAisle(locationParts[0]);
        location.setRack(locationParts[1].toInt());
        location.setShelf(locationParts[2].toInt());
    }

    //pobieranie danych z pól
    Part updatedPart (name, catalogNumber, quantity, price, location);
    updatedPart.setId(m_partId);
    return updatedPart;
}

