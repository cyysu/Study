#include "run.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    run w;
    w.show();

    return a.exec();
}
