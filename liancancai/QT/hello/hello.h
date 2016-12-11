#ifndef HELLO_H
#define HELLO_H

#include <QMainWindow>

namespace Ui {
class hello;
}

class hello : public QMainWindow
{
    Q_OBJECT

public:
    explicit hello(QWidget *parent = 0);
    ~hello();

private:
    Ui::hello *ui;
};

#endif // HELLO_H
