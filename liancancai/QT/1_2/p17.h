#ifndef P17_H
#define P17_H

#include <QMainWindow>

namespace Ui {
class P17;
}

class P17 : public QMainWindow
{
    Q_OBJECT

public:
    explicit P17(QWidget *parent = 0);
    ~P17();

private:
    Ui::P17 *ui;
};

#endif // P17_H
