/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("#centralwidget{border-image: url(:/picture/\350\223\235\350\211\262\346\270\220\345\217\230.jpg);}\n"
"#MainWindow{border-image: url(:/picture/\350\223\235\350\211\262\346\270\220\345\217\230.jpg);}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 150, 191, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("#pushButton_2{border-radius:10px;}\n"
"#pushButton_2{background-color: rgb(255, 255, 255);}\n"
""));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(180, 240, 181, 61));
        pushButton_8->setStyleSheet(QString::fromUtf8("#pushButton_8{border-radius:10px;}\n"
"#pushButton_8{background-color: rgb(255, 255, 255);}\n"
""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 330, 191, 61));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton{border-radius:10px;}\n"
"#pushButton{background-color: rgb(255, 255, 255);}\n"
""));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(180, 330, 181, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("#pushButton_3{border-radius:10px;}\n"
"#pushButton_3{background-color: rgb(255, 255, 255);}\n"
""));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(180, 150, 181, 61));
        pushButton_5->setStyleSheet(QString::fromUtf8("#pushButton_5{border-radius:10px;}\n"
"#pushButton_5{background-color: rgb(255, 255, 255);}\n"
""));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(410, 240, 191, 61));
        pushButton_9->setStyleSheet(QString::fromUtf8("#pushButton_9{border-radius:10px;}\n"
"#pushButton_9{background-color: rgb(255, 255, 255);}\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\345\214\273\347\224\237\344\277\241\346\201\257/\346\214\202\345\217\267", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "\345\214\273\346\202\243\346\262\237\351\200\232\345\271\263\345\217\260", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\347\274\226\350\276\221\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\347\227\205\346\203\205", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "\345\201\245\345\272\267\350\257\204\344\274\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
