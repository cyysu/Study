#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include <QAction>
#include <QMessageBox>

#include <QFile>//操作文件
#include <QFileDialog>//标准文件对话框
#include <QDir>//目录
#include <QTextStream>//流文件
#include <QTextEdit>



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
private slots:
    void newFileSlot();
    void openFileSlot();
    void saveFileSlot();


};

#endif // MAINWINDOW_H
