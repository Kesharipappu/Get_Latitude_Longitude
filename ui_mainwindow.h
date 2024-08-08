/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *resultTextEdit;
    QLineEdit *addressLineEdit;
    QPushButton *fetchButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(441, 360);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 70, 301, 171));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        resultTextEdit = new QTextEdit(layoutWidget);
        resultTextEdit->setObjectName("resultTextEdit");
        resultTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(resultTextEdit);

        addressLineEdit = new QLineEdit(layoutWidget);
        addressLineEdit->setObjectName("addressLineEdit");
        addressLineEdit->setStyleSheet(QString::fromUtf8("/*background-color: rgb(158, 109, 97,0%);*/\n"
" background-color: rgba(255, 255, 255, 0.8);\n"
"color: rgb(0, 0, 0);\n"
"border: 1px solid rgb(100, 100, 100);\n"
" padding: 5px;\n"
" border-radius: 5px;"));

        verticalLayout->addWidget(addressLineEdit);

        fetchButton = new QPushButton(layoutWidget);
        fetchButton->setObjectName("fetchButton");
        fetchButton->setStyleSheet(QString::fromUtf8("/*background-color: rgb(255, 132, 77);*/\n"
"QPushButton {\n"
"    background-color: rgb(255, 132, 77); /* Orange background */\n"
"    color: rgb(0, 0, 0); /* Black text */\n"
"    border: 2px solid rgb(205, 92, 92); /* Indian Red border */\n"
"    padding: 10px 20px; /* Padding for better appearance */\n"
"    border-radius: 5px; /* Rounded corners for a modern look */\n"
"    font-size: 16px; /* Adjust font size */\n"
"    font-weight: bold; /* Bold text */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease; /* Smooth transition */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(255, 69, 0); /* Red-Orange on hover */\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    border-color: rgb(255, 255, 255); /* White border on focus */\n"
"    box-shadow: 0 0 5px rgba(255, 255, 255, 0.5); /* Optional shadow on focus */\n"
"}\n"
""));

        verticalLayout->addWidget(fetchButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 441, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        resultTextEdit->setToolTip(QCoreApplication::translate("MainWindow", "Latitude and Longitude will display here...", nullptr));
#endif // QT_CONFIG(tooltip)
        resultTextEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Latitude and Longitude will display here...", nullptr));
#if QT_CONFIG(tooltip)
        addressLineEdit->setToolTip(QCoreApplication::translate("MainWindow", "Enter City Name", nullptr));
#endif // QT_CONFIG(tooltip)
        addressLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter City Name", nullptr));
#if QT_CONFIG(tooltip)
        fetchButton->setToolTip(QCoreApplication::translate("MainWindow", "Click to Fetch Latitude & Longitude", nullptr));
#endif // QT_CONFIG(tooltip)
        fetchButton->setText(QCoreApplication::translate("MainWindow", "Fetch Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
