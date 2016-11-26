#include "p17.h"
#include "ui_p17.h"

P17::P17(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::P17)
{
    ui->setupUi(this);
    this->setWindowTitle("Qt5.1 Windows Application");
    this->setWindowIcon(QIcon("/Study/liancancai/QT/1_2/ico"));

    this->setMaximumSize(300, 300);
    this->setMinimumSize(300, 300);
    this->move(100,100);
//    this->setStyleSheet("background:red");

}

P17::~P17()
{
    delete ui;
}
