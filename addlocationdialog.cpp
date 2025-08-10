#include "addlocationdialog.h"




//konstruktor dla trybu "dodaj"
AddLocationDialog::AddLocationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLocationDialog)
{
    ui->setupUi(this);
    setWindowTitle("Dodaj nową lokalizację");

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

//konstruktor dla tryby "edytuj"
AddLocationDialog::AddLocationDialog(const Location &locationToEdit, QWidget *parent) :
    QDialog (parent),
    ui(new Ui::AddLocationDialog)
{
    ui->setupUi(this);
    setWindowTitle("Edytuj lokalizację");

    ui->aisleLineEdit->setText(locationToEdit.aisle());
    ui->rackSpinBox->setValue(locationToEdit.rack());
    ui->shelfSpinBox->setValue(locationToEdit.shelf());
    m_locationId = locationToEdit.id();

}

AddLocationDialog::~AddLocationDialog()
{
    delete ui;
}

Location AddLocationDialog::getLocationData() const
{
    Location loc (ui->aisleLineEdit->text(),
                 ui->rackSpinBox->value(),
                 ui->shelfSpinBox->value());
    if(m_locationId != -1){
        loc.setId(m_locationId);
    }
    return loc;
}


