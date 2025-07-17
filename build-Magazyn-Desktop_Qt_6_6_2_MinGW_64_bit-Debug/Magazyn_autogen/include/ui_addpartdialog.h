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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addPartDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
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

    void setupUi(QDialog *addPartDialog)
    {
        if (addPartDialog->objectName().isEmpty())
            addPartDialog->setObjectName("addPartDialog");
        addPartDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(addPartDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(addPartDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 30, 223, 158));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        nameLabel = new QLabel(widget);
        nameLabel->setObjectName("nameLabel");

        horizontalLayout->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(widget);
        nameLineEdit->setObjectName("nameLineEdit");

        horizontalLayout->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        catalogNumberLabel = new QLabel(widget);
        catalogNumberLabel->setObjectName("catalogNumberLabel");

        horizontalLayout_2->addWidget(catalogNumberLabel);

        catalogNumberLineEdit = new QLineEdit(widget);
        catalogNumberLineEdit->setObjectName("catalogNumberLineEdit");

        horizontalLayout_2->addWidget(catalogNumberLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        quantityLabel = new QLabel(widget);
        quantityLabel->setObjectName("quantityLabel");

        horizontalLayout_4->addWidget(quantityLabel);

        quantitySpinBox = new QSpinBox(widget);
        quantitySpinBox->setObjectName("quantitySpinBox");

        horizontalLayout_4->addWidget(quantitySpinBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        priceLabel = new QLabel(widget);
        priceLabel->setObjectName("priceLabel");

        horizontalLayout_5->addWidget(priceLabel);

        priceDoubleSpinBox = new QDoubleSpinBox(widget);
        priceDoubleSpinBox->setObjectName("priceDoubleSpinBox");

        horizontalLayout_5->addWidget(priceDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        localtionLabel = new QLabel(widget);
        localtionLabel->setObjectName("localtionLabel");

        horizontalLayout_3->addWidget(localtionLabel);

        locationLineEdit = new QLineEdit(widget);
        locationLineEdit->setObjectName("locationLineEdit");

        horizontalLayout_3->addWidget(locationLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(addPartDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, addPartDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, addPartDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(addPartDialog);
    } // setupUi

    void retranslateUi(QDialog *addPartDialog)
    {
        addPartDialog->setWindowTitle(QCoreApplication::translate("addPartDialog", "Dialog", nullptr));
        nameLabel->setText(QCoreApplication::translate("addPartDialog", "Nazwa cz\304\231\305\233ci:", nullptr));
        catalogNumberLabel->setText(QCoreApplication::translate("addPartDialog", "Numer Katalogowy:", nullptr));
        quantityLabel->setText(QCoreApplication::translate("addPartDialog", "Ilo\305\233\304\207:", nullptr));
        priceLabel->setText(QCoreApplication::translate("addPartDialog", "Cena:", nullptr));
        localtionLabel->setText(QCoreApplication::translate("addPartDialog", "Lokalizacja:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addPartDialog: public Ui_addPartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPARTDIALOG_H
