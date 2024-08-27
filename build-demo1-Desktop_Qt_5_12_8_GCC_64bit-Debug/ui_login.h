/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QFrame *frame;
    QLineEdit *passLineEdit;
    QLabel *label;
    QLineEdit *userLineEdit;
    QPushButton *quitBtn;
    QRadioButton *doctorButton;
    QRadioButton *patientButton;
    QPushButton *logBtn;
    QPushButton *signup_btn;
    QLabel *label_2;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(1065, 603);
        login->setStyleSheet(QString::fromUtf8("#login{border-image: url(:/picture/login.png);}"));
        frame = new QFrame(login);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(90, 70, 551, 401));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        passLineEdit = new QLineEdit(frame);
        passLineEdit->setObjectName(QString::fromUtf8("passLineEdit"));
        passLineEdit->setGeometry(QRect(240, 120, 181, 31));
        passLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        passLineEdit->setEchoMode(QLineEdit::Password);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 70, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(10);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 87 20pt \"Arial Black\";\n"
"background:transparent"));
        userLineEdit = new QLineEdit(frame);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));
        userLineEdit->setGeometry(QRect(240, 70, 181, 31));
        userLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        userLineEdit->setEchoMode(QLineEdit::Normal);
        quitBtn = new QPushButton(frame);
        quitBtn->setObjectName(QString::fromUtf8("quitBtn"));
        quitBtn->setGeometry(QRect(260, 300, 89, 25));
        quitBtn->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.52, y1:1, x2:0.54, y2:0, \n"
"stop:0.0112994 rgba(64, 145, 252, 255), \n"
"stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(51, 0, 0);\n"
" \n"
"border:0px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 14pt \"Candara\";"));
        doctorButton = new QRadioButton(frame);
        doctorButton->setObjectName(QString::fromUtf8("doctorButton"));
        doctorButton->setGeometry(QRect(170, 160, 112, 23));
        doctorButton->setStyleSheet(QString::fromUtf8("background:transparent"));
        patientButton = new QRadioButton(frame);
        patientButton->setObjectName(QString::fromUtf8("patientButton"));
        patientButton->setGeometry(QRect(170, 200, 112, 23));
        patientButton->setStyleSheet(QString::fromUtf8("background:transparent"));
        logBtn = new QPushButton(frame);
        logBtn->setObjectName(QString::fromUtf8("logBtn"));
        logBtn->setGeometry(QRect(260, 180, 89, 25));
        logBtn->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.52, y1:1, x2:0.54, y2:0, \n"
"stop:0.0112994 rgba(64, 145, 252, 255), \n"
"stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(51, 0, 0);\n"
" \n"
"border:0px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 14pt \"Candara\";"));
        signup_btn = new QPushButton(frame);
        signup_btn->setObjectName(QString::fromUtf8("signup_btn"));
        signup_btn->setGeometry(QRect(260, 240, 89, 25));
        signup_btn->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.52, y1:1, x2:0.54, y2:0, \n"
"stop:0.0112994 rgba(64, 145, 252, 255), \n"
"stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(51, 0, 0);\n"
" \n"
"border:0px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 14pt \"Candara\";"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 120, 81, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font: 87 20pt \"Arial Black\";\n"
"background:transparent\n"
""));

        retranslateUi(login);
        QObject::connect(quitBtn, SIGNAL(clicked()), login, SLOT(close()));

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Form", nullptr));
        passLineEdit->setPlaceholderText(QApplication::translate("login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label->setText(QApplication::translate("login", "\347\224\250\346\210\267\345\220\215", nullptr));
        userLineEdit->setPlaceholderText(QApplication::translate("login", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        quitBtn->setText(QApplication::translate("login", "\351\200\200\345\207\272", nullptr));
        doctorButton->setText(QApplication::translate("login", "\345\214\273\347\224\237", nullptr));
        patientButton->setText(QApplication::translate("login", "\346\202\243\350\200\205", nullptr));
        logBtn->setText(QApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        signup_btn->setText(QApplication::translate("login", "\346\263\250\345\206\214", nullptr));
        label_2->setText(QApplication::translate("login", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
