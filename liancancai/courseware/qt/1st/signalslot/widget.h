#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QtDebug>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

private slots:
    void on_pushButton_clicked();
};

#endif // WIDGET_H
