#include "numbook.h"
#include "ui_numbook.h"

numbook::numbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::numbook)
{
    ui->setupUi(this);
}

numbook::~numbook()
{
    delete ui;
}
