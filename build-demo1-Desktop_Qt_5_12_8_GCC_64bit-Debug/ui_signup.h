/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QFrame *frame;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *password;
    QLineEdit *confirmword;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *username;
    QRadioButton *patient_btn;
    QRadioButton *doc_btn;

    void setupUi(QWidget *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName(QString::fromUtf8("signup"));
        signup->resize(1042, 592);
        signup->setStyleSheet(QString::fromUtf8("#signup{border-image: url(:/picture/login.png);}"));
        frame = new QFrame(signup);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 60, 521, 391));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 0, 91, 31));
        label->setStyleSheet(QString::fromUtf8("font: 87 20pt \"Arial Black\";\n"
"background:transparent"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(73, 306, 89, 25));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(29, 123, 255);\n"
"color: rgb(255, 255, 255);\n"
"font: 25 9pt \"Bahnschrift Light\";"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(74, 257, 89, 25));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(29, 123, 255);\n"
"color: rgb(255, 255, 255);\n"
"font: 25 9pt \"Bahnschrift Light\";"));
        password = new QLineEdit(frame);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(70, 113, 201, 41));
        confirmword = new QLineEdit(frame);
        confirmword->setObjectName(QString::fromUtf8("confirmword"));
        confirmword->setGeometry(QRect(70, 195, 201, 41));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 157, 111, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 87 20pt \"Arial Black\";\n"
"background:transparent"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 78, 81, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 87 20pt \"Arial Black\";\n"
"background:transparent"));
        username = new QLineEdit(frame);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(70, 38, 201, 41));
        patient_btn = new QRadioButton(frame);
        patient_btn->setObjectName(QString::fromUtf8("patient_btn"));
        patient_btn->setGeometry(QRect(330, 200, 112, 23));
        doc_btn = new QRadioButton(frame);
        doc_btn->setObjectName(QString::fromUtf8("doc_btn"));
        doc_btn->setGeometry(QRect(330, 240, 112, 23));

        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QWidget *signup)
    {
        signup->setWindowTitle(QApplication::translate("signup", "Form", nullptr));
        label->setText(QApplication::translate("signup", "\347\224\250\346\210\267\345\220\215", nullptr));
        pushButton->setText(QApplication::translate("signup", "\345\256\214\346\210\220", nullptr));
        pushButton_2->setText(QApplication::translate("signup", "\347\241\256\345\256\232", nullptr));
        password->setPlaceholderText(QApplication::translate("signup", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\345\257\206\347\240\201", nullptr));
        confirmword->setPlaceholderText(QApplication::translate("signup", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\345\257\206\347\240\201", nullptr));
        label_3->setText(QApplication::translate("signup", "\347\241\256\345\256\232\345\257\206\347\240\201", nullptr));
        label_2->setText(QApplication::translate("signup", "\345\257\206\347\240\201", nullptr));
        username->setPlaceholderText(QApplication::translate("signup", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\347\224\250\346\210\267\345\220\215", nullptr));
        patient_btn->setText(QApplication::translate("signup", "\346\202\243\350\200\205", nullptr));
        doc_btn->setText(QApplication::translate("signup", "\345\214\273\347\224\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
