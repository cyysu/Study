#include "run.h"
#include "ui_run.h"

run::run(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::run)
{
    //create
    ui->setupUi(this);
    ui->sureButton->setEnabled(false);
    QObject::connect(ui->cmdTextEdit, SIGNAL(textEdited(QString)), this,SLOT(sureButtonSlot(QString)));

}

run::~run()
{
    delete ui;
}

void run::on_sureButton_clicked()
{
    qDebug() << "sure";
}

void run::on_cancelButton_clicked()
{
    close();
}

void run::sureButtonSlot(QString)
{

}
