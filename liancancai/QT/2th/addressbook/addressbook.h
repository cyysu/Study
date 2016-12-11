#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QDialog>

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
#include <QTextStream>
#include <QMap>
#include <QMessageBox>
#include <QFileDialog>
 
namespace Ui {
class addressBook;
}

class addressBook : public QDialog
{
    Q_OBJECT

public:
    explicit addressBook(QWidget *parent = 0);
    ~addressBook();

private:
    Ui::addressBook *ui;

private:

    struct addressInfo
    {
        QString m_name;
        QString m_address;
    };

   enum nodeType
   {
        DEFAULT_NODE = 1,
        ADD_NODE = 2,
        EDIT_NODE = 3,
        OTHER_NODE = 4
   };

private:
    nodeType m_currentType;

    addressInfo m_currentInfo;
    addressInfo m_oldInfo;

    QMap<QString, QString> m_infoMap;
    QMap<QString, QString>::Iterator m_iter;

    QString m_fileName;

private:
    void createInterface();
    void createConnect();

    void updateInterface(nodeType t_nodeType);
private slots:

    void addProc();
    void editProc();
    void removeProc();
    void findProc();
    void submitProc();
    void cancelProc();
    void loadProc();
    void saveProc();
    void previousrProc();
    void nextProc();

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
