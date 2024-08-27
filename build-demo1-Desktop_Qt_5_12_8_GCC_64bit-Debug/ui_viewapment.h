/********************************************************************************
** Form generated from reading UI file 'viewapment.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWAPMENT_H
#define UI_VIEWAPMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_viewApMent
{
public:
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QPushButton *pushButton_2;
    QLineEdit *usernameEdit;
    QLabel *username;
    QPushButton *goutong;
    QPushButton *chufangyizhu;

    void setupUi(QWidget *viewApMent)
    {
        if (viewApMent->objectName().isEmpty())
            viewApMent->setObjectName(QString::fromUtf8("viewApMent"));
        viewApMent->resize(600, 500);
        pushButton = new QPushButton(viewApMent);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(510, 430, 89, 25));
        tableWidget = new QTableWidget(viewApMent);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 471, 281));
        pushButton_2 = new QPushButton(viewApMent);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 50, 89, 25));
        usernameEdit = new QLineEdit(viewApMent);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));
        usernameEdit->setGeometry(QRect(0, 350, 241, 25));
        username = new QLabel(viewApMent);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(0, 330, 91, 17));
        goutong = new QPushButton(viewApMent);
        goutong->setObjectName(QString::fromUtf8("goutong"));
        goutong->setGeometry(QRect(0, 390, 89, 25));
        chufangyizhu = new QPushButton(viewApMent);
        chufangyizhu->setObjectName(QString::fromUtf8("chufangyizhu"));
        chufangyizhu->setGeometry(QRect(0, 430, 89, 25));

        retranslateUi(viewApMent);

        QMetaObject::connectSlotsByName(viewApMent);
    } // setupUi

    void retranslateUi(QWidget *viewApMent)
    {
        viewApMent->setWindowTitle(QApplication::translate("viewApMent", "Form", nullptr));
        pushButton->setText(QApplication::translate("viewApMent", "quit", nullptr));
        pushButton_2->setText(QApplication::translate("viewApMent", "\346\230\276\347\244\272", nullptr));
        usernameEdit->setPlaceholderText(QApplication::translate("viewApMent", "\350\257\267\350\276\223\345\205\245\344\275\240\346\203\263\350\246\201\346\262\237\351\200\232\347\232\204\346\202\243\350\200\205\347\232\204\347\224\250\346\210\267\345\220\215", nullptr));
        username->setText(QApplication::translate("viewApMent", "username", nullptr));
        goutong->setText(QApplication::translate("viewApMent", "\345\214\273\346\202\243\346\262\237\351\200\232", nullptr));
        chufangyizhu->setText(QApplication::translate("viewApMent", "\345\244\204\346\226\271\345\214\273\345\230\261\347\255\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewApMent: public Ui_viewApMent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWAPMENT_H
