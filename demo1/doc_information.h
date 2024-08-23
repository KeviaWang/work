#ifndef DOC_INFORMATION_H
#define DOC_INFORMATION_H

#include <QWidget>

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
void appendOneRow(QString name,QString number);

private:
    Ui::doc_information *ui;
};

#endif // DOC_INFORMATION_H
