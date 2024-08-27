/********************************************************************************
** Form generated from reading UI file 'platform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLATFORM_H
#define UI_PLATFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_platform
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *platform)
    {
        if (platform->objectName().isEmpty())
            platform->setObjectName(QString::fromUtf8("platform"));
        platform->resize(600, 500);
        pushButton = new QPushButton(platform);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 430, 89, 25));

        retranslateUi(platform);
        QObject::connect(pushButton, SIGNAL(clicked()), platform, SLOT(close()));

        QMetaObject::connectSlotsByName(platform);
    } // setupUi

    void retranslateUi(QWidget *platform)
    {
        platform->setWindowTitle(QApplication::translate("platform", "Form", nullptr));
        pushButton->setText(QApplication::translate("platform", "quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class platform: public Ui_platform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLATFORM_H
