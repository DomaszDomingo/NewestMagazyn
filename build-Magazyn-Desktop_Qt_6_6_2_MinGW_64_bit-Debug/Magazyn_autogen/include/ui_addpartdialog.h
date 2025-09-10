/********************************************************************************
** Form generated from reading UI file 'addpartdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPARTDIALOG_H
#define UI_ADDPARTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addPartDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *windowNameLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *catalogNumberLabel;
    QLineEdit *catalogNumberLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *quantityLabel;
    QSpinBox *quantitySpinBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *priceLabel;
    QDoubleSpinBox *priceDoubleSpinBox;
    QHBoxLayout *horizontalLayout;
    QLabel *locationLabel;
    QVBoxLayout *verticalLayout_3;
    QComboBox *locationComboBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *addPartDialog)
    {
        if (addPartDialog->objectName().isEmpty())
            addPartDialog->setObjectName("addPartDialog");
        addPartDialog->resize(400, 300);
        verticalLayout_4 = new QVBoxLayout(addPartDialog);
        verticalLayout_4->setObjectName("verticalLayout_4");
        windowNameLabel = new QLabel(addPartDialog);
        windowNameLabel->setObjectName("windowNameLabel");
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        windowNameLabel->setFont(font);
        windowNameLabel->setTabletTracking(false);
        windowNameLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_4->addWidget(windowNameLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        nameLabel = new QLabel(addPartDialog);
        nameLabel->setObjectName("nameLabel");

        horizontalLayout_3->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(addPartDialog);
        nameLineEdit->setObjectName("nameLineEdit");

        horizontalLayout_3->addWidget(nameLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        catalogNumberLabel = new QLabel(addPartDialog);
        catalogNumberLabel->setObjectName("catalogNumberLabel");

        horizontalLayout_4->addWidget(catalogNumberLabel);

        catalogNumberLineEdit = new QLineEdit(addPartDialog);
        catalogNumberLineEdit->setObjectName("catalogNumberLineEdit");

        horizontalLayout_4->addWidget(catalogNumberLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        quantityLabel = new QLabel(addPartDialog);
        quantityLabel->setObjectName("quantityLabel");

        horizontalLayout_5->addWidget(quantityLabel);

        quantitySpinBox = new QSpinBox(addPartDialog);
        quantitySpinBox->setObjectName("quantitySpinBox");
        quantitySpinBox->setMaximum(999999);

        horizontalLayout_5->addWidget(quantitySpinBox);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        priceLabel = new QLabel(addPartDialog);
        priceLabel->setObjectName("priceLabel");

        horizontalLayout_6->addWidget(priceLabel);

        priceDoubleSpinBox = new QDoubleSpinBox(addPartDialog);
        priceDoubleSpinBox->setObjectName("priceDoubleSpinBox");
        priceDoubleSpinBox->setDecimals(2);
        priceDoubleSpinBox->setMaximum(99999.990000000005239);

        horizontalLayout_6->addWidget(priceDoubleSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        locationLabel = new QLabel(addPartDialog);
        locationLabel->setObjectName("locationLabel");

        horizontalLayout->addWidget(locationLabel);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        locationComboBox = new QComboBox(addPartDialog);
        locationComboBox->setObjectName("locationComboBox");

        verticalLayout_3->addWidget(locationComboBox);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(addPartDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(buttonBox);


        retranslateUi(addPartDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, addPartDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, addPartDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(addPartDialog);
    } // setupUi

    void retranslateUi(QDialog *addPartDialog)
    {
        addPartDialog->setWindowTitle(QCoreApplication::translate("addPartDialog", "Dialog", nullptr));
        windowNameLabel->setText(QCoreApplication::translate("addPartDialog", "DODAJ", nullptr));
        nameLabel->setText(QCoreApplication::translate("addPartDialog", "Nazwa cz\304\231\305\233ci:", nullptr));
        catalogNumberLabel->setText(QCoreApplication::translate("addPartDialog", "Numer Katalogowy:", nullptr));
        quantityLabel->setText(QCoreApplication::translate("addPartDialog", "Ilo\305\233\304\207:", nullptr));
        priceLabel->setText(QCoreApplication::translate("addPartDialog", "Cena:", nullptr));
        locationLabel->setText(QCoreApplication::translate("addPartDialog", "Lokalizacja: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addPartDialog: public Ui_addPartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPARTDIALOG_H
