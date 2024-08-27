/********************************************************************************
** Form generated from reading UI file 'healthassessment.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEALTHASSESSMENT_H
#define UI_HEALTHASSESSMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_healthassessment
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;
    QLabel *label;

    void setupUi(QWidget *healthassessment)
    {
        if (healthassessment->objectName().isEmpty())
            healthassessment->setObjectName(QString::fromUtf8("healthassessment"));
        healthassessment->resize(588, 560);
        healthassessment->setStyleSheet(QString::fromUtf8("#healthassessment{border-image: url(:/picture/\350\223\235\350\211\262\346\270\220\345\217\230.jpg);}\n"
""));
        lineEdit = new QLineEdit(healthassessment);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(12, 167, 201, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("#lineEdit{border-radius:5px;}\n"
"#lineEdit{background-color: rgb(255, 255, 255);}\n"
""));
        lineEdit_2 = new QLineEdit(healthassessment);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(242, 167, 201, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("#lineEdit_2{border-radius:5px;}\n"
"#lineEdit_2{background-color: rgb(255, 255, 255);}\n"
""));
        lineEdit_3 = new QLineEdit(healthassessment);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(12, 231, 201, 31));
        lineEdit_3->setStyleSheet(QString::fromUtf8("#lineEdit_3{border-radius:5px;}\n"
"#lineEdit_3{background-color: rgb(255, 255, 255);}\n"
""));
        lineEdit_4 = new QLineEdit(healthassessment);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(12, 298, 201, 31));
        lineEdit_4->setStyleSheet(QString::fromUtf8("#lineEdit_4{border-radius:5px;}\n"
"#lineEdit_4{background-color: rgb(255, 255, 255);}\n"
""));
        lineEdit_5 = new QLineEdit(healthassessment);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(241, 298, 201, 31));
        lineEdit_5->setStyleSheet(QString::fromUtf8("#lineEdit_5{border-radius:5px;}\n"
"#lineEdit_5{background-color: rgb(255, 255, 255);}\n"
""));
        lineEdit_6 = new QLineEdit(healthassessment);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(241, 230, 201, 31));
        lineEdit_6->setStyleSheet(QString::fromUtf8("#lineEdit_6{border-radius:5px;}\n"
"#lineEdit_6{background-color: rgb(255, 255, 255);}\n"
""));
        pushButton = new QPushButton(healthassessment);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 380, 91, 31));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton{border-radius:10px;}\n"
"#pushButton{background-color: rgb(255, 255, 255);}\n"
""));
        pushButton_2 = new QPushButton(healthassessment);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(471, 447, 91, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("#pushButton_2{border-radius:10px;}\n"
"#pushButton_2{background-color: rgb(255, 255, 255);}\n"
""));
        tableWidget = new QTableWidget(healthassessment);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(12, 374, 431, 151));
        tableWidget->setStyleSheet(QString::fromUtf8("#tableWidget{border-radius:5px;}\n"
"#tableWidget{background-color: rgb(255, 255, 255);}\n"
""));
        label = new QLabel(healthassessment);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 40, 141, 91));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);

        retranslateUi(healthassessment);
        QObject::connect(pushButton_2, SIGNAL(clicked()), healthassessment, SLOT(close()));

        QMetaObject::connectSlotsByName(healthassessment);
    } // setupUi

    void retranslateUi(QWidget *healthassessment)
    {
        healthassessment->setWindowTitle(QApplication::translate("healthassessment", "Form", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("healthassessment", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\350\272\253\351\253\230/m", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("healthassessment", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\344\275\223\351\207\215/kg", nullptr));
        lineEdit_3->setPlaceholderText(QApplication::translate("healthassessment", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\346\224\266\347\274\251\345\216\213/mmHg", nullptr));
        lineEdit_4->setPlaceholderText(QApplication::translate("healthassessment", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204TC\345\200\274(mmol/L)", nullptr));
        lineEdit_5->setPlaceholderText(QApplication::translate("healthassessment", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\347\251\272\350\205\271\350\241\200\347\263\226(mg/dl)", nullptr));
        lineEdit_6->setPlaceholderText(QApplication::translate("healthassessment", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\350\210\222\345\274\240\345\216\213/mmHg", nullptr));
        pushButton->setText(QApplication::translate("healthassessment", "\346\217\220\344\272\244", nullptr));
        pushButton_2->setText(QApplication::translate("healthassessment", "\350\277\224\345\233\236", nullptr));
        label->setText(QApplication::translate("healthassessment", "\345\201\245\345\272\267\350\257\204\344\274\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class healthassessment: public Ui_healthassessment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEALTHASSESSMENT_H
