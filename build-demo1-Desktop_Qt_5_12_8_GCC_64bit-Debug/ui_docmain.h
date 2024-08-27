/********************************************************************************
** Form generated from reading UI file 'docmain.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCMAIN_H
#define UI_DOCMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_docMain
{
public:
    QPushButton *pushButton;
    QPushButton *bingqingchuli;
    QPushButton *gerenxinxi;

    void setupUi(QWidget *docMain)
    {
        if (docMain->objectName().isEmpty())
            docMain->setObjectName(QString::fromUtf8("docMain"));
        docMain->resize(800, 600);
        docMain->setStyleSheet(QString::fromUtf8("#docMain{border-image: url(:/picture/\350\223\235\350\211\262\346\270\220\345\217\230.jpg);}"));
        pushButton = new QPushButton(docMain);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(590, 480, 100, 50));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton{border-radius:10px;}\n"
"#pushButton{background-color: rgb(255, 255, 255);}\n"
""));
        bingqingchuli = new QPushButton(docMain);
        bingqingchuli->setObjectName(QString::fromUtf8("bingqingchuli"));
        bingqingchuli->setGeometry(QRect(90, 200, 100, 50));
        bingqingchuli->setStyleSheet(QString::fromUtf8("#pushButton_3{border-radius:10px;}\n"
"#pushButton_3{background-color: rgb(255, 255, 255);}\n"
""));
        gerenxinxi = new QPushButton(docMain);
        gerenxinxi->setObjectName(QString::fromUtf8("gerenxinxi"));
        gerenxinxi->setGeometry(QRect(90, 100, 100, 50));
        gerenxinxi->setStyleSheet(QString::fromUtf8("#pushButton_2{border-radius:10px;}\n"
"#pushButton_2{background-color: rgb(255, 255, 255);}\n"
""));

        retranslateUi(docMain);
        QObject::connect(pushButton, SIGNAL(clicked()), docMain, SLOT(close()));

        QMetaObject::connectSlotsByName(docMain);
    } // setupUi

    void retranslateUi(QWidget *docMain)
    {
        docMain->setWindowTitle(QApplication::translate("docMain", "Form", nullptr));
        pushButton->setText(QApplication::translate("docMain", "\351\200\200\345\207\272", nullptr));
        bingqingchuli->setText(QApplication::translate("docMain", "\351\242\204\347\272\246\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        gerenxinxi->setText(QApplication::translate("docMain", "\347\274\226\350\276\221\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class docMain: public Ui_docMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCMAIN_H
