#ifndef DISEASE_H
#define DISEASE_H

#include <QWidget>
#include <QNetworkInterface>

namespace Ui {
class disease;
}

class disease : public QWidget
{
    Q_OBJECT

public:
    explicit disease(QWidget *parent = nullptr);
    ~disease();

public:
    void appendOneRow(QString name,QString dise,QString doctor,QString symptom,QString prescription,QString money,QString advice);

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::disease *ui;
};

#endif // DISEASE_H
