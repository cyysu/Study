#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QtDebug>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
//定义按钮
private:
    QPushButton *helloButton;
    QPushButton *worldButton;

//定义槽
private slots:
    void sayHelloSlot();
    void sayWorldSlot();
    void saySignalSlot();
//定义信号
signals:
    void mySignal();


};

#endif // MAINWINDOW_H
