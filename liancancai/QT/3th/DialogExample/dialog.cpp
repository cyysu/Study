#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //实现文件属性
    fileButton = new QPushButton;
    fileButton->setText(QObject::tr("标准文件对话框实例"));
    fileLineEdit = new QLineEdit;
    fileLineEdit->clear();//表示清空

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileButton,0, 0);
    mainLayout->addWidget(fileLineEdit,0,1);
    QObject::connect(fileButton,SIGNAL(clicked()), this, SLOT(showFileSlot()));

    //===color
    colorButton = new QPushButton;
    colorButton->setText(tr("标准颜色对话框实例"));
    colorFrame = new QFrame;
    colorFrame->setFrameShape(QFrame::Panel);
    colorFrame->setAutoFillBackground(true);

    mainLayout->addWidget(colorButton,1, 0);
    mainLayout->addWidget(colorFrame,1, 1);

    QObject::connect(colorButton, SIGNAL(clicked()), this, SLOT(showColorSlot()));

     //===font
    fontButton = new QPushButton;
    fontButton->setText(tr("标准字体对话框实例"));
    fontLineEdit = new QLineEdit;
    fontLineEdit->setText(tr("Welcome you"));

    mainLayout->addWidget(fontButton, 2, 0);
    mainLayout->addWidget(fontLineEdit,2,1);


    QObject::connect(fontButton, SIGNAL(clicked()), this, SLOT(showFontSlot()));

    //===input
    inputButton = new QPushButton;
    inputButton->setText(tr("标准输入对话框实例"));

    mainLayout->addWidget(inputButton,3, 0);
    QObject::connect(inputButton, SIGNAL(clicked()),this, SLOT(showInputSlot()));
    //======message
    messageBoxButton = new QPushButton;
    messageBoxButton->setText(tr("标准消息对话框实例"));

    mainLayout->addWidget(messageBoxButton, 3, 1);
    QObject::connect(messageBoxButton, SIGNAL(clicked()), this, SLOT(showMessageBoxSlot()));

}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showFileSlot()
{
    qDebug() << "file";
    QString filename = QFileDialog::getOpenFileName(this, "Open file dialog", "/tmp");
    fileLineEdit->setText(filename);
}

void Dialog::showColorSlot()
{
    QColor color = QColorDialog::getColor(Qt::white);
    if (color.isValid())//判断颜色是否有效
    {
        colorFrame->setPalette(QPalette (color));
    }
}

void Dialog::showFontSlot()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok);
    if (ok)
    {
        fontLineEdit->setFont(font);
    }
}

void Dialog::showInputSlot()
{
    inputDialog = new InputDialog(this);
    inputDialog->show();

}
void Dialog::showMessageBoxSlot()
{
    messageBoxDialog = new MessageBoxDialog(this );
    messageBoxDialog->show();
}
