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

    BigSmallButton = new QPushButton(this);
    BigSmallButton->setText("big small");
    BigSmallButton->setGeometry(100, 300, 100, 100);

    QObject::connect(ui->submitButton, SIGNAL(clicked()),this, SLOT(showFullScreen()));
    QObject::connect(ui->normalButton, SIGNAL(clicked()),this, SLOT(showNormal()));
    QObject::connect(helloButton, SIGNAL(clicked()),this, SLOT(sayHelloSlot()));
    QObject::connect(worldButton, SIGNAL(clicked()),this, SLOT(sayWorldSlot()));
    QObject::connect(this, SIGNAL(mySignal()), this, SLOT(saySignalSlot()));
    QObject::connect(this, SIGNAL(myChangeTile()), this, SLOT(myChangeTileSlot()));
    QObject::connect(BigSmallButton, SIGNAL(clicked()), this, SLOT(BigSmallButtonSlot()));
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
    emit this->myChangeTile();
}

void MainWindow::saySignalSlot()
{
    qDebug() << "mysignal";
}

void MainWindow::myChangeTileSlot()
{
    setWindowTitle("running");
}

void MainWindow::BigSmallButtonSlot()
{
    static int i = 0;

    if(0 == i)
    {
        showFullScreen();
        i = 1;
    }
    else
    {
        showNormal();
        i = 0;
    }

}
