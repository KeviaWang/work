/********************************************************************************
** Form generated from reading UI file 'doc_plat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOC_PLAT_H
#define UI_DOC_PLAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doc_plat
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *doc_plat)
    {
        if (doc_plat->objectName().isEmpty())
            doc_plat->setObjectName(QString::fromUtf8("doc_plat"));
        doc_plat->resize(600, 500);
        pushButton = new QPushButton(doc_plat);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(480, 450, 89, 25));

        retranslateUi(doc_plat);
        QObject::connect(pushButton, SIGNAL(clicked()), doc_plat, SLOT(close()));

        QMetaObject::connectSlotsByName(doc_plat);
    } // setupUi

    void retranslateUi(QWidget *doc_plat)
    {
        doc_plat->setWindowTitle(QApplication::translate("doc_plat", "Form", nullptr));
        pushButton->setText(QApplication::translate("doc_plat", "quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class doc_plat: public Ui_doc_plat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOC_PLAT_H
