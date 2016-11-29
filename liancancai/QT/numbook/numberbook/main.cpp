#include "numbook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    numbook w;
    w.show();

    return a.exec();
}
