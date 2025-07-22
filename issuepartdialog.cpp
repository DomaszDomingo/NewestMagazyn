#include "issuepartdialog.h"
#include "ui_issuepartdialog.h"
#include <QCompleter>

IssuePartDialog::IssuePartDialog(const QList <Part> &allParts,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IssuePartDialog),
    m_parts (allParts) //Zapis przekazanej listy częsci
{
    ui->setupUi(this);

    for (const Part &part : m_parts){
        //Wyświetlanie nazwy i numeru katalagowego, a w danych przechowuje id części
        ui->partComboBox->addItem(QString("%1 (%2)").arg(part.name()).arg(part.catalogNumber()),part.id());

    }

    ui->partComboBox->setEditable(true);
    auto *completer = new QCompleter(this);
    completer->setModel(ui->partComboBox->model());
    completer->setFilterMode(Qt::MatchContains); //Wyszukuj zawierające tekst
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->partComboBox->setCompleter(completer);

    //połączenie sygnału zmiany wyboru ze slotem aktualizującym UI
    connect(ui->partComboBox,QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &IssuePartDialog::onPartSelected);

    //reczne wywołanie slotu dla początkowo wybranego elementu
    if(!m_parts.isEmpty()){
        onPartSelected(0);
    }

}

IssuePartDialog::~IssuePartDialog()
{
    delete ui;
}

std::optional<IssueData> IssuePartDialog::getIssueData() const
{
    int currentIndex = ui->partComboBox->currentIndex();
    if(currentIndex < 0 ){
        return std::nullopt; // nic nie wybrano
    }

    IssueData data;
    data.partId = ui->partComboBox->itemData(currentIndex).toInt();
    data.quantity = ui->quantitySpinBox->value();

    return data;
}

//slot aktualizujący UI na podstawie wybranej części
void IssuePartDialog::onPartSelected(int index)
{
    if(index < 0 || index >= m_parts.count()){
        ui->availableQuantityLabel->setText("Dostępna ilość: 0");
        ui->quantitySpinBox->setMaximum(0);
        return;
    }

    const Part &selectedPart = m_parts.at(index);
    ui->availableQuantityLabel->setText(QString("Dostępna ilość: %1").arg(selectedPart.quantity()));
    ui->quantitySpinBox->setMaximum(selectedPart.quantity());

}



