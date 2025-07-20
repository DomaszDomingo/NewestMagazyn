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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditPartDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *windowNameLabel;
    QVBoxLayout *verticalLayout;
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
    QHBoxLayout *horizontalLayout_3;
    QLabel *localtionLabel;
    QLineEdit *locationLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditPartDialog)
    {
        if (EditPartDialog->objectName().isEmpty())
            EditPartDialog->setObjectName("EditPartDialog");
        EditPartDialog->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(EditPartDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        windowNameLabel = new QLabel(EditPartDialog);
        windowNameLabel->setObjectName("windowNameLabel");
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        windowNameLabel->setFont(font);
        windowNameLabel->setTabletTracking(false);
        windowNameLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_2->addWidget(windowNameLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        nameLabel = new QLabel(EditPartDialog);
        nameLabel->setObjectName("nameLabel");

        horizontalLayout->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(EditPartDialog);
        nameLineEdit->setObjectName("nameLineEdit");

        horizontalLayout->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        catalogNumberLabel = new QLabel(EditPartDialog);
        catalogNumberLabel->setObjectName("catalogNumberLabel");

        horizontalLayout_2->addWidget(catalogNumberLabel);

        catalogNumberLineEdit = new QLineEdit(EditPartDialog);
        catalogNumberLineEdit->setObjectName("catalogNumberLineEdit");

        horizontalLayout_2->addWidget(catalogNumberLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        quantityLabel = new QLabel(EditPartDialog);
        quantityLabel->setObjectName("quantityLabel");

        horizontalLayout_4->addWidget(quantityLabel);

        quantitySpinBox = new QSpinBox(EditPartDialog);
        quantitySpinBox->setObjectName("quantitySpinBox");
        quantitySpinBox->setMaximum(500);

        horizontalLayout_4->addWidget(quantitySpinBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        priceLabel = new QLabel(EditPartDialog);
        priceLabel->setObjectName("priceLabel");

        horizontalLayout_5->addWidget(priceLabel);

        priceDoubleSpinBox = new QDoubleSpinBox(EditPartDialog);
        priceDoubleSpinBox->setObjectName("priceDoubleSpinBox");
        priceDoubleSpinBox->setMaximum(99999999.989999994635582);

        horizontalLayout_5->addWidget(priceDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        localtionLabel = new QLabel(EditPartDialog);
        localtionLabel->setObjectName("localtionLabel");

        horizontalLayout_3->addWidget(localtionLabel);

        locationLineEdit = new QLineEdit(EditPartDialog);
        locationLineEdit->setObjectName("locationLineEdit");

        horizontalLayout_3->addWidget(locationLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(EditPartDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


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
        localtionLabel->setText(QCoreApplication::translate("EditPartDialog", "Lokalizacja:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditPartDialog: public Ui_EditPartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPARTDIALOG_H
