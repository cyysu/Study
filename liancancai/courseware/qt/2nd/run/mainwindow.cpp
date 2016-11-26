#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->submitButton->setEnabled(false);
    QObject::connect(ui->cmdLineEdit, SIGNAL(textEdited(QString)), this, SLOT(buttonEnableSlot(QString)));
    QObject::connect(ui->cmdLineEdit, SIGNAL(returnPressed()),this, SLOT(startProcessSlot()));
    QObject::connect(ui->submitButton, SIGNAL(clicked()), this, SLOT(startProcessSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startProcessSlot()
{
    qDebug() << "start process";
    /*
    QProcess *myProcess = new QProcess(parent);
     myProcess->start(program, arguments);
     */
    QProcess *process = new QProcess;
    QString s = ui->cmdLineEdit->text();

    /*qDebug()<< s.length();
    qDebug() << s.size();
    s = s.trimmed();
    qDebug()<< s.length();
    qDebug() << s.size();
    */
    //表示执行命令
    //trimmed() 表示删除字符串后面空格
    process->start(s.trimmed());
    //表示清空QLineEdit控件信息
    ui->cmdLineEdit->clear();
    //关闭运行窗口
    this->close();

}

void MainWindow::buttonEnableSlot(QString text)
{
    //ui->cmdLineEdit->clear();
    //qDebug() << text;
    if (text.size() == 0)
    {
        ui->submitButton->setEnabled(false);
    }
    else
    {
     ui->submitButton->setEnabled(true);
    }
}
