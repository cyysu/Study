#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtDebug>
//===file include==
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QFileDialog>
//===color include==
#include <QColorDialog>
#include <QFrame>//用户设置颜色背景
//======Font include
#include <QFontDialog>

//====input
#include "inputdialog.h"



namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

private:
    //====file option
    QPushButton *fileButton;
    QLineEdit *fileLineEdit;
    QGridLayout *mainLayout;
    //==== color option
    QPushButton *colorButton;
    QFrame *colorFrame;
    //===font
    QPushButton *fontButton;
    QLineEdit *fontLineEdit;
    // === input
    QPushButton *inputButton;
    InputDialog *inputDialog;


private slots:
    void showFileSlot();//表示文件槽
    void showColorSlot();
    void showFontSlot();
    void showInputSlot();
};

#endif // DIALOG_H
