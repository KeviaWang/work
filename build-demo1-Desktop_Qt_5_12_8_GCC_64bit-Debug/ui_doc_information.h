/********************************************************************************
** Form generated from reading UI file 'doc_information.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOC_INFORMATION_H
#define UI_DOC_INFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doc_information
{
public:
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;

    void setupUi(QWidget *doc_information)
    {
        if (doc_information->objectName().isEmpty())
            doc_information->setObjectName(QString::fromUtf8("doc_information"));
        doc_information->resize(600, 500);
        doc_information->setStyleSheet(QString::fromUtf8("#doc_information{border-image: url(:/picture/\350\223\235\350\211\262\346\270\220\345\217\230.jpg);}"));
        pushButton = new QPushButton(doc_information);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(500, 440, 89, 25));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton{border-radius:10px;}\n"
"#pushButton{background-color: rgb(255, 255, 255);}\n"
""));
        tableWidget = new QTableWidget(doc_information);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 491, 381));
        pushButton_2 = new QPushButton(doc_information);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(500, 400, 89, 25));
        pushButton_2->setStyleSheet(QString::fromUtf8("#pushButton_2{border-radius:10px;}\n"
"#pushButton_2{background-color: rgb(255, 255, 255);}\n"
""));
        lineEdit = new QLineEdit(doc_information);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(4, 400, 201, 25));
        lineEdit->setStyleSheet(QString::fromUtf8("#lineEdit{border-radius:5px;}\n"
"#lineEdit{background-color: rgb(255, 255, 255);}\n"
""));
        pushButton_3 = new QPushButton(doc_information);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(4, 440, 89, 25));
        pushButton_3->setStyleSheet(QString::fromUtf8("#pushButton_3{border-radius:10px;}\n"
"#pushButton_3{background-color: rgb(255, 255, 255);}\n"
""));

        retranslateUi(doc_information);
        QObject::connect(pushButton, SIGNAL(clicked()), doc_information, SLOT(close()));

        QMetaObject::connectSlotsByName(doc_information);
    } // setupUi

    void retranslateUi(QWidget *doc_information)
    {
        doc_information->setWindowTitle(QApplication::translate("doc_information", "Form", nullptr));
        pushButton->setText(QApplication::translate("doc_information", "\351\200\200\345\207\272", nullptr));
        pushButton_2->setText(QApplication::translate("doc_information", "\347\241\256\345\256\232", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("doc_information", "\350\257\267\350\276\223\345\205\245\344\275\240\346\203\263\351\242\204\345\256\232\347\232\204\345\214\273\347\224\237\345\247\223\345\220\215", nullptr));
        pushButton_3->setText(QApplication::translate("doc_information", "\351\242\204\347\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class doc_information: public Ui_doc_information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOC_INFORMATION_H
