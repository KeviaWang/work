/********************************************************************************
** Form generated from reading UI file 'doc_edit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOC_EDIT_H
#define UI_DOC_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doc_edit
{
public:
    QPushButton *pushButton;
    QLineEdit *nameEdit;
    QLineEdit *genderEdit;
    QLineEdit *roomEdit;
    QLineEdit *contactEdit;
    QLineEdit *majorEdit;
    QLineEdit *yearEdit;
    QLineEdit *positionEdit;
    QPushButton *pushButton_2;

    void setupUi(QWidget *doc_edit)
    {
        if (doc_edit->objectName().isEmpty())
            doc_edit->setObjectName(QString::fromUtf8("doc_edit"));
        doc_edit->resize(668, 549);
        doc_edit->setStyleSheet(QString::fromUtf8("#doc_edit{border-image: url(:/picture/\350\223\235\350\211\262\346\270\220\345\217\230.jpg);}"));
        pushButton = new QPushButton(doc_edit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(500, 484, 91, 31));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton{border-radius:10px;}\n"
"#pushButton{background-color: rgb(255, 255, 255);}\n"
""));
        nameEdit = new QLineEdit(doc_edit);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(30, 40, 251, 31));
        nameEdit->setStyleSheet(QString::fromUtf8("#nameEdit{border-radius:5px;}\n"
"#nameEdit{background-color: rgb(255, 255, 255);}\n"
""));
        genderEdit = new QLineEdit(doc_edit);
        genderEdit->setObjectName(QString::fromUtf8("genderEdit"));
        genderEdit->setGeometry(QRect(30, 90, 251, 31));
        genderEdit->setStyleSheet(QString::fromUtf8("#genderEdit{border-radius:5px;}\n"
"#genderEdit{background-color: rgb(255, 255, 255);}\n"
""));
        roomEdit = new QLineEdit(doc_edit);
        roomEdit->setObjectName(QString::fromUtf8("roomEdit"));
        roomEdit->setGeometry(QRect(30, 140, 251, 31));
        roomEdit->setStyleSheet(QString::fromUtf8("#roomEdit{border-radius:5px;}\n"
"#roomEdit{background-color: rgb(255, 255, 255);}\n"
""));
        contactEdit = new QLineEdit(doc_edit);
        contactEdit->setObjectName(QString::fromUtf8("contactEdit"));
        contactEdit->setGeometry(QRect(30, 190, 251, 31));
        contactEdit->setStyleSheet(QString::fromUtf8("#contactEdit{border-radius:5px;}\n"
"#contactEdit{background-color: rgb(255, 255, 255);}\n"
""));
        majorEdit = new QLineEdit(doc_edit);
        majorEdit->setObjectName(QString::fromUtf8("majorEdit"));
        majorEdit->setGeometry(QRect(30, 240, 251, 31));
        majorEdit->setStyleSheet(QString::fromUtf8("#majorEdit{border-radius:5px;}\n"
"#majorEdit{background-color: rgb(255, 255, 255);}\n"
""));
        yearEdit = new QLineEdit(doc_edit);
        yearEdit->setObjectName(QString::fromUtf8("yearEdit"));
        yearEdit->setGeometry(QRect(30, 290, 251, 31));
        yearEdit->setStyleSheet(QString::fromUtf8("#yearEdit{border-radius:5px;}\n"
"#yearEdit{background-color: rgb(255, 255, 255);}\n"
""));
        positionEdit = new QLineEdit(doc_edit);
        positionEdit->setObjectName(QString::fromUtf8("positionEdit"));
        positionEdit->setGeometry(QRect(30, 340, 251, 31));
        positionEdit->setStyleSheet(QString::fromUtf8("#positionEdit{border-radius:5px;}\n"
"#positionEdit{background-color: rgb(255, 255, 255);}\n"
""));
        pushButton_2 = new QPushButton(doc_edit);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(500, 430, 91, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("#pushButton_2{border-radius:10px;}\n"
"#pushButton_2{background-color: rgb(255, 255, 255);}\n"
""));

        retranslateUi(doc_edit);
        QObject::connect(pushButton, SIGNAL(clicked()), doc_edit, SLOT(close()));

        QMetaObject::connectSlotsByName(doc_edit);
    } // setupUi

    void retranslateUi(QWidget *doc_edit)
    {
        doc_edit->setWindowTitle(QApplication::translate("doc_edit", "Form", nullptr));
        pushButton->setText(QApplication::translate("doc_edit", "\350\277\224\345\233\236", nullptr));
        nameEdit->setPlaceholderText(QApplication::translate("doc_edit", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\345\247\223\345\220\215", nullptr));
        genderEdit->setPlaceholderText(QApplication::translate("doc_edit", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\346\200\247\345\210\253", nullptr));
        roomEdit->setPlaceholderText(QApplication::translate("doc_edit", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\347\247\221\345\256\244", nullptr));
        contactEdit->setPlaceholderText(QApplication::translate("doc_edit", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\350\201\224\347\263\273\346\226\271\345\274\217", nullptr));
        majorEdit->setPlaceholderText(QApplication::translate("doc_edit", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\344\270\223\344\270\232\351\242\206\345\237\237", nullptr));
        yearEdit->setPlaceholderText(QApplication::translate("doc_edit", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\345\267\245\344\275\234\345\271\264\351\231\220", nullptr));
        positionEdit->setPlaceholderText(QApplication::translate("doc_edit", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\350\201\214\344\275\215", nullptr));
        pushButton_2->setText(QApplication::translate("doc_edit", "\345\275\225\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class doc_edit: public Ui_doc_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOC_EDIT_H
