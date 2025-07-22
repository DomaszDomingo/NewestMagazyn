/********************************************************************************
** Form generated from reading UI file 'issuepartdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ISSUEPARTDIALOG_H
#define UI_ISSUEPARTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_IssuePartDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *nameLabel;
    QComboBox *partComboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *availableQuantityLabel;
    QSpinBox *quantitySpinBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *IssuePartDialog)
    {
        if (IssuePartDialog->objectName().isEmpty())
            IssuePartDialog->setObjectName("IssuePartDialog");
        IssuePartDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(IssuePartDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        nameLabel = new QLabel(IssuePartDialog);
        nameLabel->setObjectName("nameLabel");

        horizontalLayout->addWidget(nameLabel);

        partComboBox = new QComboBox(IssuePartDialog);
        partComboBox->setObjectName("partComboBox");

        horizontalLayout->addWidget(partComboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        availableQuantityLabel = new QLabel(IssuePartDialog);
        availableQuantityLabel->setObjectName("availableQuantityLabel");

        horizontalLayout_2->addWidget(availableQuantityLabel);

        quantitySpinBox = new QSpinBox(IssuePartDialog);
        quantitySpinBox->setObjectName("quantitySpinBox");

        horizontalLayout_2->addWidget(quantitySpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(IssuePartDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(IssuePartDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, IssuePartDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, IssuePartDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(IssuePartDialog);
    } // setupUi

    void retranslateUi(QDialog *IssuePartDialog)
    {
        IssuePartDialog->setWindowTitle(QCoreApplication::translate("IssuePartDialog", "Dialog", nullptr));
        nameLabel->setText(QCoreApplication::translate("IssuePartDialog", "Nazwa", nullptr));
        availableQuantityLabel->setText(QCoreApplication::translate("IssuePartDialog", "Ilo\305\233c do wydania", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IssuePartDialog: public Ui_IssuePartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ISSUEPARTDIALOG_H
