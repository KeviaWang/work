#ifndef VIEWAPMENT_H
#define VIEWAPMENT_H

#include <QWidget>

namespace Ui {
class viewApMent;
}

class viewApMent : public QWidget
{
    Q_OBJECT

public:
    explicit viewApMent(QWidget *parent = nullptr);
    ~viewApMent();
public:
    void appendOneRow(QString name,QString gender,QString birth,QString height,QString weight,QString disease,QString family_history);

private slots:
    void on_pushButton_2_clicked();

    void on_goutong_clicked();

    void on_chufangyizhu_clicked();

private:
    Ui::viewApMent *ui;
};

#endif // VIEWAPMENT_H
