/********************************************************************************
** Form generated from reading UI file 'addlocationdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDLOCATIONDIALOG_H
#define UI_ADDLOCATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddLocationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *aisleLabel;
    QLineEdit *aisleLineEdit;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *rackLabel;
    QSpinBox *rackSpinBox;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *shelfLabel;
    QSpinBox *shelfSpinBox;
    QSpacerItem *horizontalSpacer_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddLocationDialog)
    {
        if (AddLocationDialog->objectName().isEmpty())
            AddLocationDialog->setObjectName("AddLocationDialog");
        AddLocationDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(AddLocationDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        aisleLabel = new QLabel(AddLocationDialog);
        aisleLabel->setObjectName("aisleLabel");

        horizontalLayout->addWidget(aisleLabel);

        aisleLineEdit = new QLineEdit(AddLocationDialog);
        aisleLineEdit->setObjectName("aisleLineEdit");
        aisleLineEdit->setMinimumSize(QSize(40, 25));
        aisleLineEdit->setMaximumSize(QSize(40, 25));

        horizontalLayout->addWidget(aisleLineEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        rackLabel = new QLabel(AddLocationDialog);
        rackLabel->setObjectName("rackLabel");

        horizontalLayout_2->addWidget(rackLabel);

        rackSpinBox = new QSpinBox(AddLocationDialog);
        rackSpinBox->setObjectName("rackSpinBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(40);
        sizePolicy.setVerticalStretch(25);
        sizePolicy.setHeightForWidth(rackSpinBox->sizePolicy().hasHeightForWidth());
        rackSpinBox->setSizePolicy(sizePolicy);
        rackSpinBox->setMinimumSize(QSize(40, 25));
        rackSpinBox->setMaximumSize(QSize(40, 25));
        rackSpinBox->setMaximum(999);

        horizontalLayout_2->addWidget(rackSpinBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        shelfLabel = new QLabel(AddLocationDialog);
        shelfLabel->setObjectName("shelfLabel");

        horizontalLayout_3->addWidget(shelfLabel);

        shelfSpinBox = new QSpinBox(AddLocationDialog);
        shelfSpinBox->setObjectName("shelfSpinBox");
        sizePolicy.setHeightForWidth(shelfSpinBox->sizePolicy().hasHeightForWidth());
        shelfSpinBox->setSizePolicy(sizePolicy);
        shelfSpinBox->setMinimumSize(QSize(40, 25));
        shelfSpinBox->setMaximumSize(QSize(40, 25));

        horizontalLayout_3->addWidget(shelfSpinBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);

        buttonBox = new QDialogButtonBox(AddLocationDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddLocationDialog);

        QMetaObject::connectSlotsByName(AddLocationDialog);
    } // setupUi

    void retranslateUi(QDialog *AddLocationDialog)
    {
        AddLocationDialog->setWindowTitle(QCoreApplication::translate("AddLocationDialog", "Dialog", nullptr));
        aisleLabel->setText(QCoreApplication::translate("AddLocationDialog", "Alejka", nullptr));
        rackLabel->setText(QCoreApplication::translate("AddLocationDialog", "Rega\305\202", nullptr));
        shelfLabel->setText(QCoreApplication::translate("AddLocationDialog", "P\303\263\305\202ka", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddLocationDialog: public Ui_AddLocationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLOCATIONDIALOG_H
