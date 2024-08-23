#ifndef PER_INFORMATION_H
#define PER_INFORMATION_H

#include <QWidget>

namespace Ui {
class per_information;
}

class per_information : public QWidget
{
    Q_OBJECT

public:
    explicit per_information(QWidget *parent = nullptr);
    ~per_information();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::per_information *ui;
};

#endif // PER_INFORMATION_H
