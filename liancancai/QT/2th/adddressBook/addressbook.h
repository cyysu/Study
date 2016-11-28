#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>

#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QFile>
#include <QMessageBox>
#include <QMap>
#include <QTextStream>

class addressBook : public QMainWindow
{
    Q_OBJECT

public:
    addressBook(QWidget *parent = 0);
    ~addressBook();

private:
    void createInterface();

private:
    QGridLayout *m_gLayout;
    QVBoxLayout *m_vLayout;
    QHBoxLayout *m_hLayout;

    QLabel *m_nameLabel;
    QLabel *m_addressLabel;

    QLineEdit *m_nameEdit;
    QTextEdit *m_addressEdit;

    QPushButton *m_addBtn;
    QPushButton *m_editBtn;
    QPushButton *m_removeBtn;
    QPushButton *m_findBtn;
    QPushButton *m_submitBtn;
    QPushButton *m_cancelBtn;
    QPushButton *m_loadBtn;
    QPushButton *m_saveBtn;
    QPushButton *m_previousBtn;
    QPushButton *m_nextBtn;

};

#endif // ADDRESSBOOK_H
