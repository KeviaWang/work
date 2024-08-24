#ifndef DOC_EDIT_H
#define DOC_EDIT_H

#include <QWidget>

namespace Ui {
class doc_edit;
}

class doc_edit : public QWidget
{
    Q_OBJECT

public:
    explicit doc_edit(QWidget *parent = nullptr);
    ~doc_edit();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::doc_edit *ui;
};

#endif // DOC_EDIT_H
