#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>

namespace Ui {
class clock;
}

class clock : public QWidget
{
    Q_OBJECT

public:
    explicit clock(QWidget *parent = 0);
    ~clock();

private:
    Ui::clock *ui;
};

#endif // CLOCK_H
