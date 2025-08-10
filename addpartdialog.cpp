#include "addpartdialog.h"
#include "ui_addpartdialog.h"


addPartDialog::addPartDialog(const QList<Location> &availableLocations, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addPartDialog)
    , m_locations(availableLocations)
{
    ui->setupUi(this);
    setWindowTitle("Dodaj nową część");

    for (const Location &loc : m_locations){
        ui->locationComboBox->addItem(loc.toString());
    }
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

    int currentIndex = ui->locationComboBox->currentIndex();
    Location selectedLocation = m_locations.at(currentIndex);


    return Part (name, catalogNumber, quantity, price, selectedLocation);
}
