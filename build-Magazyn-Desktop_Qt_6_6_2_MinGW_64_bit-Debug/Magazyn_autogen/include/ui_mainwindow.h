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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *historyButton;
    QTableView *partsTableView;
    QChartView *quantityChartView;
    QPushButton *issueButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 10, 592, 436));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);

        editButton = new QPushButton(layoutWidget);
        editButton->setObjectName("editButton");

        horizontalLayout->addWidget(editButton);

        deleteButton = new QPushButton(layoutWidget);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout->addWidget(deleteButton);

        historyButton = new QPushButton(layoutWidget);
        historyButton->setObjectName("historyButton");

        horizontalLayout->addWidget(historyButton);


        verticalLayout->addLayout(horizontalLayout);

        partsTableView = new QTableView(layoutWidget);
        partsTableView->setObjectName("partsTableView");
        partsTableView->setMinimumSize(QSize(500, 200));
        partsTableView->setBaseSize(QSize(3, 0));

        verticalLayout->addWidget(partsTableView);


        verticalLayout_2->addLayout(verticalLayout);

        quantityChartView = new QChartView(layoutWidget);
        quantityChartView->setObjectName("quantityChartView");

        verticalLayout_2->addWidget(quantityChartView);


        horizontalLayout_2->addLayout(verticalLayout_2);

        issueButton = new QPushButton(layoutWidget);
        issueButton->setObjectName("issueButton");

        horizontalLayout_2->addWidget(issueButton);

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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
