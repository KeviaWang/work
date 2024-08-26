#include "guahao.h"
#include "ui_guahao.h"

#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>

Guahao::Guahao(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Guahao)
{
    ui->setupUi(this);

    // 初始化数据库连接
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("timeslot.db"); // 确保数据库路径正确

    if (!db.open()) {
        QMessageBox::critical(this, "数据库错误", "无法连接到数据库：" + db.lastError().text());
        return;
    }

    // 连接日期选择器的信号到槽函数
    connect(ui->dateEdit, &QDateEdit::dateChanged, this, &Guahao::onDateChanged);
    // 初始填充 ComboBox
    onDateChanged();  // 默认情况下加载当前日期的可用时间段
}

Guahao::~Guahao()
{
    delete ui;
}

void Guahao::onDateChanged()
{
    QDate selectedDate = ui->dateEdit->date();
    populateComboBox();  // 先清空并重新填充 ComboBox
    disableSelectedOptions(selectedDate);
}

void Guahao::populateComboBox()
{
    // 清空 ComboBox 的所有选项
    ui->comboBox->clear();

    // 添加一个空白项作为默认值
    ui->comboBox->addItem("");

    // 添加时间段到 ComboBox
    ui->comboBox->addItem("9:00~10:00");
    ui->comboBox->addItem("10:00~11:00");
    ui->comboBox->addItem("14:00~15:00");
    ui->comboBox->addItem("15:00~16:00");
}

void Guahao::disableSelectedOptions(const QDate &date)
{
    QSqlQuery query(db);
    query.prepare("SELECT time_slot FROM TimeSlotSelection WHERE date = :date");
    query.bindValue(":date", date.toString("yyyy-MM-dd"));

    if (query.exec()) {
        while (query.next()) {
            QString selectedSlot = query.value(0).toString();

            // 获取选项索引
            int index = ui->comboBox->findText(selectedSlot);
            if (index != -1) {
                // 禁用已被选择的选项
                ui->comboBox->setItemData(index, 0, Qt::UserRole - 1);
            }
        }
    } else {
        qDebug() << "查询失败：" << query.lastError().text();
    }
}

void Guahao::on_pushButton_clicked()
{
    // 禁用按钮以防止重复点击
    ui->pushButton->setEnabled(false);

    // 获取选择的日期和时间段
    QDate selectedDate = ui->dateEdit->date();
    QString selectedSlot = ui->comboBox->currentText();

    if (selectedSlot.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择一个时间段！");
        ui->pushButton->setEnabled(true);  // 重新启用按钮
        return;
    }

    // 插入数据到数据库
    QSqlQuery query(db);
    query.prepare("INSERT INTO TimeSlotSelection (date, time_slot) VALUES (:date, :time_slot)");

    // 绑定参数
    query.bindValue(":date", selectedDate.toString("yyyy-MM-dd"));
    query.bindValue(":time_slot", selectedSlot);

    // 打印 SQL 和绑定的参数
    qDebug() << "SQL Query:" << query.executedQuery();
    qDebug() << "Bound values:";
    qDebug() << ":date =" << selectedDate.toString("yyyy-MM-dd");
    qDebug() << ":time_slot =" << selectedSlot;

    // 执行 SQL 语句
    if (query.exec()) {
        QMessageBox::information(this, "成功", "预约成功！");
        close();  // 关闭窗口
    } else {
        // 获取并显示详细的错误信息
        QMessageBox::critical(this, "错误", "插入失败：" + query.lastError().text());
        ui->pushButton->setEnabled(true);  // 重新启用按钮
    }
}
