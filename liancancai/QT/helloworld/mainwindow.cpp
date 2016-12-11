#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //create a QLable
    QLabel *label = new QLabel(this);

    label->setText("Hello World");
    label->setGeometry(201, 26, 200, 25);
}

MainWindow::~MainWindow()
{
    delete ui;
}
