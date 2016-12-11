#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QLabel label(&w);


    /*
    //获取字符编码名称
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    //设置
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(codec);
    */
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    w.setWindowTitle(QObject::tr("runing 窗口"));
    //w.setWindowTitle("runing 窗口");
    label.setText(QObject::tr("hello, 你好"));
    w.show();

    return a.exec();
}
