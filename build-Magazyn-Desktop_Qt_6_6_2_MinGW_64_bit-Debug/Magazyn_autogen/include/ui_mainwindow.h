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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *TabWidget;
    QWidget *Materials;
    QWidget *layoutWidget;
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
    QWidget *Locations;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QTableView *locationsTableView;
    QVBoxLayout *verticalLayout_4;
    QPushButton *addLocationButton;
    QPushButton *pushButton;
    QPushButton *deleteLocationButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        TabWidget = new QTabWidget(centralwidget);
        TabWidget->setObjectName("TabWidget");
        TabWidget->setEnabled(true);
        TabWidget->setGeometry(QRect(20, 30, 750, 500));
        Materials = new QWidget();
        Materials->setObjectName("Materials");
        layoutWidget = new QWidget(Materials);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 712, 436));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
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


        verticalLayout_2->addLayout(verticalLayout);

        partsTableView = new QTableView(layoutWidget);
        partsTableView->setObjectName("partsTableView");
        partsTableView->setMinimumSize(QSize(500, 200));
        partsTableView->setBaseSize(QSize(3, 0));

        verticalLayout_2->addWidget(partsTableView);

        quantityChartView = new QChartView(layoutWidget);
        quantityChartView->setObjectName("quantityChartView");

        verticalLayout_2->addWidget(quantityChartView);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        issueButton = new QPushButton(layoutWidget);
        issueButton->setObjectName("issueButton");

        verticalLayout_3->addWidget(issueButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        issueModeComboBox = new QComboBox(layoutWidget);
        issueModeComboBox->addItem(QString());
        issueModeComboBox->addItem(QString());
        issueModeComboBox->setObjectName("issueModeComboBox");

        horizontalLayout_2->addWidget(issueModeComboBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer_2);

        issueModeLabel = new QLabel(layoutWidget);
        issueModeLabel->setObjectName("issueModeLabel");

        horizontalLayout_2->addWidget(issueModeLabel);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        TabWidget->addTab(Materials, QString());
        Locations = new QWidget();
        Locations->setObjectName("Locations");
        layoutWidget1 = new QWidget(Locations);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 10, 258, 256));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        locationsTableView = new QTableView(layoutWidget1);
        locationsTableView->setObjectName("locationsTableView");

        verticalLayout_5->addWidget(locationsTableView);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        addLocationButton = new QPushButton(layoutWidget1);
        addLocationButton->setObjectName("addLocationButton");

        verticalLayout_4->addWidget(addLocationButton);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName("pushButton");

        verticalLayout_4->addWidget(pushButton);

        deleteLocationButton = new QPushButton(layoutWidget1);
        deleteLocationButton->setObjectName("deleteLocationButton");

        verticalLayout_4->addWidget(deleteLocationButton);


        verticalLayout_5->addLayout(verticalLayout_4);

        TabWidget->addTab(Locations, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        TabWidget->setCurrentIndex(1);


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
        TabWidget->setTabText(TabWidget->indexOf(Materials), QCoreApplication::translate("MainWindow", "Materia\305\202y", nullptr));
        addLocationButton->setText(QCoreApplication::translate("MainWindow", "Dodaj", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Edytuj", nullptr));
        deleteLocationButton->setText(QCoreApplication::translate("MainWindow", "Usu\305\204", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(Locations), QCoreApplication::translate("MainWindow", "Lokalizacje", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
