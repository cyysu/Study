#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0, 0, 600, 400);

    helloButton = new QPushButton(this);
    helloButton->setText("hello");
    helloButton->setGeometry(100, 50, 100, 100);

    worldButton = new QPushButton(this);
    worldButton->setText("world");
    worldButton->setGeometry(100, 200, 100, 100);
    QObject::connect(ui->submitButton, SIGNAL(clicked()),this, SLOT(showFullScreen()));
    QObject::connect(ui->normalButton, SIGNAL(clicked()),this, SLOT(showNormal()));
    QObject::connect(helloButton, SIGNAL(clicked()),this, SLOT(sayHelloSlot()));
    QObject::connect(worldButton, SIGNAL(clicked()),this, SLOT(sayWorldSlot()));
    QObject::connect(this, SIGNAL(mySignal()), this, SLOT(saySignalSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sayHelloSlot()
{
    qDebug() << "hello";
    emit this->mySignal();//发射信号
}
void MainWindow::sayWorldSlot()
{
    qDebug() << "world";
}

void MainWindow::saySignalSlot()
{
    qDebug() << "mysignal";
}
