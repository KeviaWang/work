#ifndef DISEASE_H
#define DISEASE_H

#include <QWidget>

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
    void appendOneRow(QString name,QString dise);

private:
    Ui::disease *ui;
};

#endif // DISEASE_H
