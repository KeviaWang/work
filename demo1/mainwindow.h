#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainwidget.h"

#include <QMainWindow>
#include <QNetworkInterface>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    MainWidget *mainwidget;

};
#endif // MAINWINDOW_H
