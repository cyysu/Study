#ifndef MESSAGEBOXDIALOG_H
#define MESSAGEBOXDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QtDebug>

class MessageBoxDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MessageBoxDialog(QWidget *parent = 0);

signals:
private:
        QLabel *label;
        QPushButton *questionButton;
        QPushButton *informationButton;
        QPushButton *warningButton;
        QPushButton *criticalButton;
        QPushButton *aboutButton;
        QPushButton *aboutQtButton;
        QGridLayout *mainLayout;



public slots:
        void showQuestionMsgSlot();
        void showInformationMsgSlot();
        void showWarningMsgSlot();
        void showCriticalMsgSlot();
        void showAboutMsgSlot();
        void showAboutQtMsgSlot();

};

#endif // MESSAGEBOXDIALOG_H
