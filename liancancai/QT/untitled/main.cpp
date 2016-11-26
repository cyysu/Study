#include "hello.h"
#include <QApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hello w;
    w.show();

    cout << "hello" << endl;
    return a.exec();
}
