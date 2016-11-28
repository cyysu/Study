#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>
#include <stdio.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    MainWindow w;
    //printf("this is a c hello!\n");
    w.show();

    return a.exec();
}
