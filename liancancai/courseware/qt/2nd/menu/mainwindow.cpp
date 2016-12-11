#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->newaction,SIGNAL(triggered()),this, SLOT(newFileSlot()));
    QObject::connect(ui->openaction,SIGNAL(triggered()),this, SLOT(openFileSlot()));
    QObject::connect(ui->saveaction, SIGNAL(triggered()), this, SLOT(saveFileSlot()));
    QObject::connect(ui->exitaction, SIGNAL(triggered()), this, SLOT(close()));

    //表示撤销
    QObject::connect(ui->undoaction, SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
    //表示重做
    QObject::connect(ui->reaction, SIGNAL(triggered()),ui->textEdit, SLOT(redo()));
    QObject::connect(ui->copy_t, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    QObject::connect(ui->pasteaction, SIGNAL(triggered()), ui->textEdit, SLOT(paste()));
    QObject::connect(ui->cutaction, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    QObject::connect(ui->selectaction, SIGNAL(triggered()), ui->textEdit, SLOT(selectAll()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFileSlot()
{
    qDebug() << "newfile";
    if(ui->textEdit->document()->isModified())
    {
        QMessageBox::question(this, tr("记事本"),tr("文件已经修改，是否保存?"), QMessageBox::Ok | QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Save);
        ui->textEdit->clear();
    }
    else
    {}
}

void MainWindow::openFileSlot()
{
    //获取文件名
    QString filename = QFileDialog::getOpenFileName(this, tr("open file box"),QDir::currentPath());
    qDebug() << "filename : " << filename;

    if (filename.isEmpty())
    {
        QMessageBox::information(this, tr("Error Mesaage"), tr("file not find!"));
        return ;
    }
    //打开文件
    QFile *file = new QFile;
    file->setFileName(filename);//表示设置文件名到文件对象中
    //打开文件
    bool ok;
    ok = file->open(QIODevice::ReadOnly);
    if (ok)
    {
        qDebug() << "open success";
        QTextStream in(file);//帮定文件和流
        ui->textEdit->setText(in.readAll());
    }
    else
    {
        qDebug() << "open failed";
    }
}
void MainWindow::saveFileSlot()
{
    //获取文件名
    QString filename = QFileDialog::getSaveFileName(this, tr("open file box"),QDir::currentPath());
    qDebug() << "filename : " << filename;

    if (filename.isEmpty())
    {
        QMessageBox::information(this, tr("Error Mesaage"), tr("file not find!"));
        return ;
    }
    //打开文件
    QFile *file = new QFile;
    file->setFileName(filename);//表示设置文件名到文件对象中
    //打开文件
    bool ok;
    ok = file->open(QIODevice::WriteOnly);
    if (ok)
    {
        QTextStream out(file);
        out << ui->textEdit->toPlainText();//转换成纯文本
        file->close();
        delete file;
    }
    else
    {

    }
}
