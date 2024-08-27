/********************************************************************************
** Form generated from reading UI file 'disease.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISEASE_H
#define UI_DISEASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_disease
{
public:
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QPushButton *pushButton_2;

    void setupUi(QWidget *disease)
    {
        if (disease->objectName().isEmpty())
            disease->setObjectName(QString::fromUtf8("disease"));
        disease->resize(800, 600);
        pushButton = new QPushButton(disease);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(690, 510, 89, 25));
        tableWidget = new QTableWidget(disease);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 671, 541));
        pushButton_2 = new QPushButton(disease);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(690, 470, 89, 25));

        retranslateUi(disease);
        QObject::connect(pushButton, SIGNAL(clicked()), disease, SLOT(close()));

        QMetaObject::connectSlotsByName(disease);
    } // setupUi

    void retranslateUi(QWidget *disease)
    {
        disease->setWindowTitle(QApplication::translate("disease", "Form", nullptr));
        pushButton->setText(QApplication::translate("disease", "quit", nullptr));
        pushButton_2->setText(QApplication::translate("disease", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class disease: public Ui_disease {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISEASE_H
