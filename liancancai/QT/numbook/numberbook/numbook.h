#ifndef NUMBOOK_H
#define NUMBOOK_H

#include <QDialog>

namespace Ui {
class numbook;
}

class numbook : public QDialog
{
    Q_OBJECT

public:
    explicit numbook(QWidget *parent = 0);
    ~numbook();

private:
    Ui::numbook *ui;
};

#endif // NUMBOOK_H
