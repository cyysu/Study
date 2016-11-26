#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->resultButton, SIGNAL(clicked()), this, SLOT(addSlot()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//实现槽
void MainWindow::addSlot()
{
    //表示把获取字符串转换成int类型
    int first = ui->fristLineEdit->text().toInt();
    int second = ui->secondLineEdit->text().toInt();
    int result;

    if (ui->comboBox->currentIndex() == 0)
    {
        result = first + second;
        ui->resultLineEdit->setText(QString::number(result));
    }
    if (ui->comboBox->currentIndex() == 1)
    {
        result = first - second;
        ui->resultLineEdit->setText(QString::number(result));

        if (second == 0)
        {
            QMessageBox::warning(this, "Zreo", "second noenable zero");
        }
        else
        {
        QMessageBox::information(this, "result add", QString::number(result));
        }
    }
}
