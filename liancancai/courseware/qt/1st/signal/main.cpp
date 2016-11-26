#include <QtGui/QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setGeometry(0,0,600,400);
    QPushButton *titleButton;
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    titleButton = new QPushButton(&w);
    titleButton->setGeometry(100,100,100,100);

    titleButton->setText(QObject::tr("改变标题"));


    QObject::connect(titleButton, SIGNAL(clicked()),&w,SLOT(changeTitleslot()));
    w.show();

    return a.exec();
}
