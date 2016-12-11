#include <QtGui/QApplication>
#include "dialog.h"
#include <QTextCodec>
#include <QString>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    Dialog w;
    //显示中文字符

    w.setWindowTitle(QObject::tr("各种标准对话框的实例"));

    w.show();

    return a.exec();
}
