#include "addressbook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    addressBook w;
    w.show();

    return a.exec();
}
