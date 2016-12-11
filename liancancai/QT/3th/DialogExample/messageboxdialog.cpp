#include "messageboxdialog.h"

MessageBoxDialog::MessageBoxDialog(QWidget *parent) :
    QDialog(parent)
{
    this->setWindowTitle(tr("标准消息对话框的实例"));
    label = new QLabel;
    label->setText(tr("请选择一种消息框"));

    questionButton = new QPushButton;
    questionButton->setText(tr("question box"));

    informationButton = new QPushButton;
    informationButton->setText(tr("information box"));

    warningButton = new QPushButton;
    warningButton->setText(tr("warning box"));


    criticalButton = new QPushButton;
    criticalButton->setText(tr("critical box"));


    aboutButton = new QPushButton;
    aboutButton->setText(tr("about box"));

    aboutQtButton = new QPushButton;
    aboutQtButton->setText(tr("aboutQt box"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label, 0, 0);
    mainLayout->addWidget(questionButton,1, 0);
    mainLayout->addWidget(informationButton,1, 1);
    mainLayout->addWidget(warningButton,2, 0);
    mainLayout->addWidget(criticalButton,2, 1);
    mainLayout->addWidget(aboutButton,3, 0);
    mainLayout->addWidget(aboutQtButton,3, 1);

    QObject::connect(questionButton, SIGNAL(clicked()), this, SLOT(showQuestionMsgSlot()));
    QObject::connect(informationButton, SIGNAL(clicked()), this, SLOT(showInformationMsgSlot()));
    QObject::connect(warningButton, SIGNAL(clicked()), this, SLOT(showWarningMsgSlot()));
    QObject::connect(criticalButton, SIGNAL(clicked()), this, SLOT(showCriticalMsgSlot()));
    QObject::connect(aboutButton, SIGNAL(clicked()), this, SLOT(showAboutMsgSlot()));
    QObject::connect(aboutQtButton, SIGNAL(clicked()), this, SLOT(showAboutQtMsgSlot()));

}

void MessageBoxDialog::showQuestionMsgSlot()
{
    qDebug() << "question";
    label->setText(tr("question message box"));
    switch (QMessageBox::question(this, tr("question对话框"),tr("你现在修改文件已经完成，是否结束程序？"),
                          QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Cancel))
    {
        case QMessageBox::Ok:
            label->setText(tr("ok"));
            break;
        case QMessageBox::Cancel:
            label->setText("cancel");
            break;
        default:
            label->setText("other");
            break;
    }

}
void MessageBoxDialog::showInformationMsgSlot()
{
    qDebug() << "information";
    label->setText(tr("information message box"));
    QMessageBox::information(this, tr("information 对话框"),tr("这是一个information测试框！"));
}
void MessageBoxDialog::showWarningMsgSlot()
{
    qDebug() << "warning";
    label->setText(tr("warning message box"));
    QMessageBox::warning(this,tr("warning 对话框"),tr("这是一个warning的测试框"));

}
void MessageBoxDialog::showCriticalMsgSlot()
{
    qDebug() << "critical";
    label->setText(tr("critical message box"));
    QMessageBox::critical(this,tr("critical 对话框"),tr("这是一个critical的测试框"));
}
void MessageBoxDialog::showAboutMsgSlot()
{
    qDebug() << "about";
    label->setText(tr("about message box"));
    QMessageBox::about(this,tr("about 对话框"),tr("这是一个about的测试框"));
}
void MessageBoxDialog::showAboutQtMsgSlot()
{
    qDebug() << "aboutQt";
    label->setText(tr("aboutQt message box"));
    QMessageBox::aboutQt(this,tr("aboutQt 对话框"));
}
