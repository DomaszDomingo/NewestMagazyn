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


// Metoda, która zbiera dane z pól
Part addPartDialog::getPartData() const
{
    QString name = ui->nameLineEdit->text();
    QString catalogNumber = ui->catalogNumberLineEdit->text();
    int quantity = ui->quantitySpinBox->value();
    double price = ui->priceDoubleSpinBox->value();


    //Lokalizacja pobierana jako prosty tekst. Do rozbudowy w przyszłości
    Location location (ui->locationLineEdit->text(),0,0);

    return Part (name, catalogNumber, quantity, price, location);
}
