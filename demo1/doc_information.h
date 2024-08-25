#ifndef DOC_INFORMATION_H
#define DOC_INFORMATION_H

#include <QWidget>
#include <QNetworkInterface>

namespace Ui {
class doc_information;
}

class doc_information : public QWidget
{
    Q_OBJECT

public:
    explicit doc_information(QWidget *parent = nullptr);
    ~doc_information();
public:
void appendOneRow(QString name,QString gender,QString room,QString contact,QString positon,QString major,QString year);

private slots:
void on_pushButton_3_clicked();

void on_pushButton_2_clicked();

private:
    Ui::doc_information *ui;
};

#endif // DOC_INFORMATION_H
