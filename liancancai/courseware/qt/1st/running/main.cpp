#include <QtGui/QApplication>
#include "widget.h"
#include <QtDebug>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    const int a1 = 10, b = 20;

    qDebug("a = %d", a1);
    qDebug() << "b = " << b;


    w.move(0,400);//设置位置
    w.setWindowTitle("runing...");//设置标签
    //qDebug() << "hello";
    //qDebug() << "w.y = " << w.y;
    w.show();

    return a.exec();
}
