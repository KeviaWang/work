/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QPushButton *sendButton;
    QTextEdit *textDisplay;
    QLineEdit *inputField;
    QLineEdit *ipEdit;
    QLineEdit *sendEdit;
    QLineEdit *rcvEdit;
    QPushButton *connectButton;
    QPushButton *SelectFileButton;
    QPushButton *quitButton;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(800, 600);
        sendButton = new QPushButton(MainWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(560, 530, 89, 25));
        textDisplay = new QTextEdit(MainWidget);
        textDisplay->setObjectName(QString::fromUtf8("textDisplay"));
        textDisplay->setGeometry(QRect(40, 70, 481, 371));
        inputField = new QLineEdit(MainWidget);
        inputField->setObjectName(QString::fromUtf8("inputField"));
        inputField->setGeometry(QRect(40, 530, 481, 25));
        ipEdit = new QLineEdit(MainWidget);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));
        ipEdit->setGeometry(QRect(650, 90, 113, 25));
        sendEdit = new QLineEdit(MainWidget);
        sendEdit->setObjectName(QString::fromUtf8("sendEdit"));
        sendEdit->setGeometry(QRect(650, 150, 113, 25));
        rcvEdit = new QLineEdit(MainWidget);
        rcvEdit->setObjectName(QString::fromUtf8("rcvEdit"));
        rcvEdit->setGeometry(QRect(650, 210, 113, 25));
        connectButton = new QPushButton(MainWidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(660, 290, 89, 25));
        SelectFileButton = new QPushButton(MainWidget);
        SelectFileButton->setObjectName(QString::fromUtf8("SelectFileButton"));
        SelectFileButton->setGeometry(QRect(220, 480, 89, 25));
        quitButton = new QPushButton(MainWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(730, 0, 51, 31));

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", nullptr));
        sendButton->setText(QApplication::translate("MainWidget", "send", nullptr));
        connectButton->setText(QApplication::translate("MainWidget", "connect", nullptr));
        SelectFileButton->setText(QApplication::translate("MainWidget", "selectFile", nullptr));
        quitButton->setText(QApplication::translate("MainWidget", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
