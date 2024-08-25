#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDateChanged();
    void on_pushButton_clicked();

private:
    void populateComboBox();
    void disableSelectedOptions(const QDate &date);

    Ui::MainWindow *ui;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
