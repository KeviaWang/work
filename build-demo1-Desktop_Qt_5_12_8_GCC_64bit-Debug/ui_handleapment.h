/********************************************************************************
** Form generated from reading UI file 'handleapment.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDLEAPMENT_H
#define UI_HANDLEAPMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_handleApment
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *bingliEdit;
    QLineEdit *chufangEdit;
    QLineEdit *yizhuEdit;
    QLineEdit *jiaofeiEdit;
    QPushButton *tijiaoBtn;

    void setupUi(QWidget *handleApment)
    {
        if (handleApment->objectName().isEmpty())
            handleApment->setObjectName(QString::fromUtf8("handleApment"));
        handleApment->resize(600, 500);
        pushButton = new QPushButton(handleApment);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(460, 440, 89, 25));
        label = new QLabel(handleApment);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 67, 17));
        label_2 = new QLabel(handleApment);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 120, 67, 17));
        label_3 = new QLabel(handleApment);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 200, 67, 17));
        label_4 = new QLabel(handleApment);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 280, 67, 17));
        bingliEdit = new QLineEdit(handleApment);
        bingliEdit->setObjectName(QString::fromUtf8("bingliEdit"));
        bingliEdit->setGeometry(QRect(150, 40, 200, 25));
        chufangEdit = new QLineEdit(handleApment);
        chufangEdit->setObjectName(QString::fromUtf8("chufangEdit"));
        chufangEdit->setGeometry(QRect(150, 120, 200, 25));
        yizhuEdit = new QLineEdit(handleApment);
        yizhuEdit->setObjectName(QString::fromUtf8("yizhuEdit"));
        yizhuEdit->setGeometry(QRect(150, 200, 200, 25));
        jiaofeiEdit = new QLineEdit(handleApment);
        jiaofeiEdit->setObjectName(QString::fromUtf8("jiaofeiEdit"));
        jiaofeiEdit->setGeometry(QRect(150, 280, 200, 25));
        tijiaoBtn = new QPushButton(handleApment);
        tijiaoBtn->setObjectName(QString::fromUtf8("tijiaoBtn"));
        tijiaoBtn->setGeometry(QRect(460, 390, 89, 25));

        retranslateUi(handleApment);
        QObject::connect(pushButton, SIGNAL(clicked()), handleApment, SLOT(close()));

        QMetaObject::connectSlotsByName(handleApment);
    } // setupUi

    void retranslateUi(QWidget *handleApment)
    {
        handleApment->setWindowTitle(QApplication::translate("handleApment", "Form", nullptr));
        pushButton->setText(QApplication::translate("handleApment", "quit", nullptr));
        label->setText(QApplication::translate("handleApment", "\347\227\205\344\276\213", nullptr));
        label_2->setText(QApplication::translate("handleApment", "\345\244\204\346\226\271", nullptr));
        label_3->setText(QApplication::translate("handleApment", "\345\214\273\345\230\261", nullptr));
        label_4->setText(QApplication::translate("handleApment", "\347\274\264\350\264\271", nullptr));
        tijiaoBtn->setText(QApplication::translate("handleApment", "\346\217\220\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class handleApment: public Ui_handleApment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLEAPMENT_H
