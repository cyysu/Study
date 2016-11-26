#ifndef RUN_H
#define RUN_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <QProcess>

namespace Ui {
class run;
}

class run : public QMainWindow
{
    Q_OBJECT

public:
    explicit run(QWidget *parent = 0);
    ~run();

private slots:
    void on_sureButton_clicked();

    void on_cancelButton_clicked();

    void on_cmdTextEdit_textChanged();

    void sureButtonSlot(QString);

private:
    Ui::run *ui;
};

#endif // RUN_H
