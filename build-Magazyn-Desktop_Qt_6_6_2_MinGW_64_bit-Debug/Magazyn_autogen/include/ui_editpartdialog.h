/********************************************************************************
** Form generated from reading UI file 'editpartdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPARTDIALOG_H
#define UI_EDITPARTDIALOG_H

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

class Ui_EditPartDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *windowNameLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *catalogNumberLabel;
    QLineEdit *catalogNumberLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *quantityLabel;
    QSpinBox *quantitySpinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *priceLabel;
    QDoubleSpinBox *priceDoubleSpinBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *locationLabel;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *aisleLabel;
    QLineEdit *aisleLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *rackLabel;
    QSpinBox *rackSpinBox;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *shelfLabel;
    QSpinBox *shelfSpinBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditPartDialog)
    {
        if (EditPartDialog->objectName().isEmpty())
            EditPartDialog->setObjectName("EditPartDialog");
        EditPartDialog->resize(400, 300);
        verticalLayout_4 = new QVBoxLayout(EditPartDialog);
        verticalLayout_4->setObjectName("verticalLayout_4");
        windowNameLabel = new QLabel(EditPartDialog);
        windowNameLabel->setObjectName("windowNameLabel");
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        windowNameLabel->setFont(font);
        windowNameLabel->setTabletTracking(false);
        windowNameLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_4->addWidget(windowNameLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        nameLabel = new QLabel(EditPartDialog);
        nameLabel->setObjectName("nameLabel");

        horizontalLayout->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(EditPartDialog);
        nameLineEdit->setObjectName("nameLineEdit");

        horizontalLayout->addWidget(nameLineEdit);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        catalogNumberLabel = new QLabel(EditPartDialog);
        catalogNumberLabel->setObjectName("catalogNumberLabel");

        horizontalLayout_2->addWidget(catalogNumberLabel);

        catalogNumberLineEdit = new QLineEdit(EditPartDialog);
        catalogNumberLineEdit->setObjectName("catalogNumberLineEdit");

        horizontalLayout_2->addWidget(catalogNumberLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        quantityLabel = new QLabel(EditPartDialog);
        quantityLabel->setObjectName("quantityLabel");

        horizontalLayout_4->addWidget(quantityLabel);

        quantitySpinBox = new QSpinBox(EditPartDialog);
        quantitySpinBox->setObjectName("quantitySpinBox");
        quantitySpinBox->setMaximum(500);

        horizontalLayout_4->addWidget(quantitySpinBox);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        priceLabel = new QLabel(EditPartDialog);
        priceLabel->setObjectName("priceLabel");

        horizontalLayout_5->addWidget(priceLabel);

        priceDoubleSpinBox = new QDoubleSpinBox(EditPartDialog);
        priceDoubleSpinBox->setObjectName("priceDoubleSpinBox");
        priceDoubleSpinBox->setMaximum(99999999.989999994635582);

        horizontalLayout_5->addWidget(priceDoubleSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        locationLabel = new QLabel(EditPartDialog);
        locationLabel->setObjectName("locationLabel");

        horizontalLayout_7->addWidget(locationLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        aisleLabel = new QLabel(EditPartDialog);
        aisleLabel->setObjectName("aisleLabel");
        aisleLabel->setMaximumSize(QSize(39, 25));

        verticalLayout_3->addWidget(aisleLabel);

        aisleLineEdit = new QLineEdit(EditPartDialog);
        aisleLineEdit->setObjectName("aisleLineEdit");
        aisleLineEdit->setMaximumSize(QSize(39, 25));

        verticalLayout_3->addWidget(aisleLineEdit);


        horizontalLayout_6->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        rackLabel = new QLabel(EditPartDialog);
        rackLabel->setObjectName("rackLabel");

        verticalLayout->addWidget(rackLabel);

        rackSpinBox = new QSpinBox(EditPartDialog);
        rackSpinBox->setObjectName("rackSpinBox");

        verticalLayout->addWidget(rackSpinBox);


        horizontalLayout_6->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        shelfLabel = new QLabel(EditPartDialog);
        shelfLabel->setObjectName("shelfLabel");

        verticalLayout_2->addWidget(shelfLabel);

        shelfSpinBox = new QSpinBox(EditPartDialog);
        shelfSpinBox->setObjectName("shelfSpinBox");

        verticalLayout_2->addWidget(shelfSpinBox);


        horizontalLayout_6->addLayout(verticalLayout_2);


        horizontalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(horizontalLayout_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(EditPartDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(buttonBox);


        retranslateUi(EditPartDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditPartDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditPartDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditPartDialog);
    } // setupUi

    void retranslateUi(QDialog *EditPartDialog)
    {
        EditPartDialog->setWindowTitle(QCoreApplication::translate("EditPartDialog", "Dialog", nullptr));
        windowNameLabel->setText(QCoreApplication::translate("EditPartDialog", "EDYCJA", nullptr));
        nameLabel->setText(QCoreApplication::translate("EditPartDialog", "Nazwa cz\304\231\305\233ci:", nullptr));
        catalogNumberLabel->setText(QCoreApplication::translate("EditPartDialog", "Numer Katalogowy:", nullptr));
        quantityLabel->setText(QCoreApplication::translate("EditPartDialog", "Ilo\305\233\304\207:", nullptr));
        priceLabel->setText(QCoreApplication::translate("EditPartDialog", "Cena:", nullptr));
        locationLabel->setText(QCoreApplication::translate("EditPartDialog", "Lokalizacja", nullptr));
        aisleLabel->setText(QCoreApplication::translate("EditPartDialog", "Alejka", nullptr));
        rackLabel->setText(QCoreApplication::translate("EditPartDialog", "Rega\305\202", nullptr));
        shelfLabel->setText(QCoreApplication::translate("EditPartDialog", "P\303\263\305\202ka", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditPartDialog: public Ui_EditPartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPARTDIALOG_H
