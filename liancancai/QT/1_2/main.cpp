#include "p17.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    P17 w;
    w.show();

    return a.exec();
}
