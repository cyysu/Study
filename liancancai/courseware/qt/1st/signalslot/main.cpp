#include <QtGui/QApplication>
#include "widget.h"
#include <QSpinBox>
#include <QSlider>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    //定义
    QSpinBox *spinbox = new QSpinBox(&w);
    spinbox->setRange(0,1000);
    spinbox->setSingleStep(10);

    //定义进度条
    QSlider *slider = new QSlider(&w);
    slider->setOrientation(Qt::Horizontal);
    slider->setGeometry(100,100,200,20);
    slider->setRange(0,1000);//表示取值范围
    slider->setSingleStep(10);//表示每次增加10

    QObject::connect(spinbox, SIGNAL(valueChanged(int)),slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)),spinbox, SLOT(setValue(int)));

    w.show();

    return a.exec();
}
