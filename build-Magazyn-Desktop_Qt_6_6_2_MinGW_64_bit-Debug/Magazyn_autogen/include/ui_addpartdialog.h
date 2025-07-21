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
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLabel *aisleLabel;
    QLineEdit *aisleLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *rackLabel;
    QSpinBox *rackSpinBox;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QLabel *shelfLabel;
    QSpinBox *shelfSpinBox;
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

        horizontalLayout_5->addWidget(quantitySpinBox);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        priceLabel = new QLabel(addPartDialog);
        priceLabel->setObjectName("priceLabel");

        horizontalLayout_6->addWidget(priceLabel);

        priceDoubleSpinBox = new QDoubleSpinBox(addPartDialog);
        priceDoubleSpinBox->setObjectName("priceDoubleSpinBox");

        horizontalLayout_6->addWidget(priceDoubleSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        locationLabel = new QLabel(addPartDialog);
        locationLabel->setObjectName("locationLabel");

        horizontalLayout->addWidget(locationLabel);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        aisleLabel = new QLabel(addPartDialog);
        aisleLabel->setObjectName("aisleLabel");
        aisleLabel->setMaximumSize(QSize(39, 25));

        verticalLayout_3->addWidget(aisleLabel);

        aisleLineEdit = new QLineEdit(addPartDialog);
        aisleLineEdit->setObjectName("aisleLineEdit");
        aisleLineEdit->setEnabled(true);
        aisleLineEdit->setMaximumSize(QSize(39, 25));
        aisleLineEdit->setBaseSize(QSize(0, 0));

        verticalLayout_3->addWidget(aisleLineEdit);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        rackLabel = new QLabel(addPartDialog);
        rackLabel->setObjectName("rackLabel");

        verticalLayout_2->addWidget(rackLabel);

        rackSpinBox = new QSpinBox(addPartDialog);
        rackSpinBox->setObjectName("rackSpinBox");

        verticalLayout_2->addWidget(rackSpinBox);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        shelfLabel = new QLabel(addPartDialog);
        shelfLabel->setObjectName("shelfLabel");

        verticalLayout->addWidget(shelfLabel);

        shelfSpinBox = new QSpinBox(addPartDialog);
        shelfSpinBox->setObjectName("shelfSpinBox");

        verticalLayout->addWidget(shelfSpinBox);


        horizontalLayout->addLayout(verticalLayout);


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
        aisleLabel->setText(QCoreApplication::translate("addPartDialog", "Alejka", nullptr));
        rackLabel->setText(QCoreApplication::translate("addPartDialog", "Rega\305\202", nullptr));
        shelfLabel->setText(QCoreApplication::translate("addPartDialog", "P\303\263\305\202ka", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addPartDialog: public Ui_addPartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPARTDIALOG_H
