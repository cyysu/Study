#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QtDebug>
#include <QInputDialog>//表示输入姓名 性别 年龄 成绩

class InputDialog : public QDialog
{
    Q_OBJECT
public:
    explicit InputDialog(QWidget *parent = 0);

signals:

private:
   QLabel *nameLabel1;
   QLabel *nameLabel2;
   QPushButton *nameButton;

   QLabel *sexLabel1;
   QLabel *sexLabel2;
   QPushButton *sexButton;

   QLabel *ageLabel1;
   QLabel *ageLabel2;
   QPushButton *ageButton;

   QLabel *resultLabel1;
   QLabel *resultLabel2;
   QPushButton *resultButton;

   QGridLayout *mainLayout;

public slots:
   void changeNameSlot();
   void changeSexSlot();
   void changeAgeSlot();
   void changeResultSlot();



};

#endif // INPUTDIALOG_H
