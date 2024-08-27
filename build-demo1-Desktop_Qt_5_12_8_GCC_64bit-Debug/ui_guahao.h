/********************************************************************************
** Form generated from reading UI file 'guahao.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUAHAO_H
#define UI_GUAHAO_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Guahao
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Guahao)
    {
        if (Guahao->objectName().isEmpty())
            Guahao->setObjectName(QString::fromUtf8("Guahao"));
        Guahao->resize(800, 600);
        Guahao->setStyleSheet(QString::fromUtf8("#centralwidget{border-image: url(:/background/\350\223\235\350\211\262\346\270\220\345\217\230.jpg);}\n"
"#Guahao{border-image: url(:/background/\350\223\235\350\211\262\346\270\220\345\217\230.jpg);}\n"
""));
        centralwidget = new QWidget(Guahao);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 60, 271, 71));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 180, 191, 41));
        label_2->setFont(font);
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(280, 170, 271, 61));
        dateEdit->setDate(QDate(2024, 8, 29));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(121, 278, 191, 41));
        label_3->setFont(font);
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(280, 270, 271, 61));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 400, 141, 51));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton{border-radius:10px;}\n"
"#pushButton{background-color: rgb(255, 255, 255);}\n"
""));
        Guahao->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Guahao);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Guahao->setMenuBar(menubar);
        statusbar = new QStatusBar(Guahao);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Guahao->setStatusBar(statusbar);

        retranslateUi(Guahao);

        QMetaObject::connectSlotsByName(Guahao);
    } // setupUi

    void retranslateUi(QMainWindow *Guahao)
    {
        Guahao->setWindowTitle(QApplication::translate("Guahao", "Guahao", nullptr));
        label->setText(QApplication::translate("Guahao", "\350\257\267\351\200\211\346\213\251\351\242\204\347\272\246\346\227\245\346\234\237\345\222\214\346\227\266\351\227\264", nullptr));
        label_2->setText(QApplication::translate("Guahao", "\351\242\204\347\272\246\346\227\245\346\234\237:", nullptr));
        dateEdit->setDisplayFormat(QApplication::translate("Guahao", "yyyy/MM/dd", nullptr));
        label_3->setText(QApplication::translate("Guahao", "\351\242\204\347\272\246\346\227\266\351\227\264:", nullptr));
        pushButton->setText(QApplication::translate("Guahao", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Guahao: public Ui_Guahao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUAHAO_H

