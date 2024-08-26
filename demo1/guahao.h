#ifndef GUAHAO_H
#define GUAHAO_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class Guahao; }  // 这只是一个前向声明
QT_END_NAMESPACE

class Guahao : public QMainWindow
{
    Q_OBJECT

public:
    Guahao(QWidget *parent = nullptr);
    ~Guahao();

private slots:
    void onDateChanged();
    void on_pushButton_clicked();

private:
    void populateComboBox();
    void disableSelectedOptions(const QDate &date);

    Ui::Guahao *ui;
    QSqlDatabase db;
};

#endif // GUAHAO_H
