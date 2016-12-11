#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QObject::connect(ui->closeButton, SIGNAL(clicked()),this,SLOT(close()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeTitleslot()
{
    //qDebug() << "hello";
    this->setWindowTitle("runing...");
}
