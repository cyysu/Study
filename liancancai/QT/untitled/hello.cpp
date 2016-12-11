#include "hello.h"
#include "ui_hello.h"

hello::hello(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hello)
{
    ui->setupUi(this);
}

hello::~hello()
{
    delete ui;
}
