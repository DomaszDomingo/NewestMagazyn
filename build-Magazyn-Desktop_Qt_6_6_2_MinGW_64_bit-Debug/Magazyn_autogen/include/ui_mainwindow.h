/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *historyButton;
    QTableView *partsTableView;
    QChartView *quantityChartView;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *issueButton;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *issueModeComboBox;
    QSpacerItem *verticalSpacer_2;
    QLabel *issueModeLabel;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(9, 9, 712, 436));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addButton = new QPushButton(widget);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);

        editButton = new QPushButton(widget);
        editButton->setObjectName("editButton");

        horizontalLayout->addWidget(editButton);

        deleteButton = new QPushButton(widget);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout->addWidget(deleteButton);

        historyButton = new QPushButton(widget);
        historyButton->setObjectName("historyButton");

        horizontalLayout->addWidget(historyButton);


        verticalLayout->addLayout(horizontalLayout);

        partsTableView = new QTableView(widget);
        partsTableView->setObjectName("partsTableView");
        partsTableView->setMinimumSize(QSize(500, 200));
        partsTableView->setBaseSize(QSize(3, 0));

        verticalLayout->addWidget(partsTableView);


        verticalLayout_2->addLayout(verticalLayout);

        quantityChartView = new QChartView(widget);
        quantityChartView->setObjectName("quantityChartView");

        verticalLayout_2->addWidget(quantityChartView);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        issueButton = new QPushButton(widget);
        issueButton->setObjectName("issueButton");

        verticalLayout_3->addWidget(issueButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        issueModeComboBox = new QComboBox(widget);
        issueModeComboBox->addItem(QString());
        issueModeComboBox->addItem(QString());
        issueModeComboBox->setObjectName("issueModeComboBox");

        horizontalLayout_2->addWidget(issueModeComboBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer_2);

        issueModeLabel = new QLabel(widget);
        issueModeLabel->setObjectName("issueModeLabel");

        horizontalLayout_2->addWidget(issueModeLabel);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Dodaj", nullptr));
        editButton->setText(QCoreApplication::translate("MainWindow", "Edytuj", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Usu\305\204", nullptr));
        historyButton->setText(QCoreApplication::translate("MainWindow", "Historia", nullptr));
        issueButton->setText(QCoreApplication::translate("MainWindow", "Wydaj", nullptr));
        issueModeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "FIFO", nullptr));
        issueModeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "LIFO", nullptr));

        issueModeLabel->setText(QCoreApplication::translate("MainWindow", "Wybierz tryb\n"
" wydania", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
