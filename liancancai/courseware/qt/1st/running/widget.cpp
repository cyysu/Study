#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setMaximumSize(360,150);
    this->setMinimumSize(360,150);
}

Widget::~Widget()
{
    delete ui;
}
