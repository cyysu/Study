#include "addressbook.h"
#include "ui_addressbook.h"

addressBook::addressBook(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::addressBook),

    //initialize data
    m_gLayout(0), m_vLayout(0), m_hLayout(0),
    m_nameLabel(0), m_addressLabel(0),
    m_nameEdit(0), m_addressEdit(0),
    m_addBtn(0), m_editBtn(0), m_removeBtn(0),
    m_findBtn(0), m_submitBtn(0), m_cancelBtn(0),
    m_loadBtn(0), m_saveBtn(0), m_previousBtn(0),
    m_nextBtn(0), m_currentType(DEFAULT_NODE)
{
    ui->setupUi(this);
    createInterface();
    createConnect();
}

addressBook::~addressBook()
{
    delete ui;
}

void addressBook::createInterface()
{
    m_gLayout = new QGridLayout(this);
    m_vLayout = new QVBoxLayout;
    m_hLayout = new QHBoxLayout;

    m_nameLabel = new QLabel("Name :", this);
    m_addressLabel = new QLabel("Address :", this);

    m_nameEdit = new QLineEdit();
    m_addressEdit = new QTextEdit();

    m_addBtn = new QPushButton("Add", this);
    m_editBtn = new QPushButton("Edit", this);
    m_removeBtn = new QPushButton("Remove", this);
    m_findBtn = new  QPushButton("Find", this);
    m_submitBtn = new QPushButton("Submit", this);
    m_cancelBtn = new QPushButton("Cancel", this);
    m_loadBtn = new QPushButton("Load...", this);
    m_saveBtn = new QPushButton("Save...", this);
    m_previousBtn = new QPushButton("Previous", this);
    m_nextBtn = new QPushButton("Next", this);

    //add Button to vLayout
    m_vLayout->addWidget(m_addBtn);
    m_vLayout->addWidget(m_editBtn);
    m_vLayout->addWidget(m_removeBtn);
    m_vLayout->addWidget(m_findBtn);
    m_vLayout->addWidget(m_submitBtn);
    m_vLayout->addWidget(m_cancelBtn);
    m_vLayout->addWidget(m_loadBtn);
    m_vLayout->addWidget(m_saveBtn);

    // add button to hLayout
    m_hLayout->addWidget(m_previousBtn);
    m_hLayout->addWidget(m_nextBtn);

    // assign grid
    m_gLayout->addWidget(m_nameLabel, 0, 0);
    m_gLayout->addWidget(m_nameEdit, 0, 1);
    m_gLayout->addWidget(m_addressLabel, 1, 0, Qt::AlignTop);
    m_gLayout->addWidget(m_addressEdit, 1, 1);
    m_gLayout->addLayout(m_vLayout, 1 ,2, Qt::AlignTop);
    m_gLayout->addLayout(m_hLayout, 2, 1);

    //change Windows Title
    this->setWindowTitle("地址簿");

    //hid submit,cancel button
    m_submitBtn->hide();
    m_cancelBtn->hide();

    //name,address edit just read
    m_nameEdit->setReadOnly(true);
    m_addressEdit->setReadOnly(true);

    //disable corrsponding button
    m_editBtn->setDisabled(true);
    m_removeBtn->setDisabled(true);
    m_findBtn->setDisabled(true);
    m_submitBtn->setDisabled(true);
    m_cancelBtn->setDisabled(true);
    m_saveBtn->setDisabled(true);
    m_previousBtn->setDisabled(true);
    m_nextBtn->setDisabled(true);

}

void addressBook::createConnect()
{
    //connect all button
    connect(m_addBtn, SIGNAL(clicked()), this, SLOT(addProc()));
    connect(m_editBtn, SIGNAL(clicked()), this, SLOT(editProc()));
    connect(m_removeBtn, SIGNAL(clicked()), this, SLOT(removeProc()));
    connect(m_findBtn, SIGNAL(clicked()), this, SLOT(findProc()));
    connect(m_submitBtn, SIGNAL(clicked()), this, SLOT(submitProc()));
    connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(cancelProc()));
    connect(m_loadBtn, SIGNAL(clicked()), this, SLOT(loadProc()));
    connect(m_saveBtn, SIGNAL(clicked()), this, SLOT(saveProc()));
    connect(m_previousBtn, SIGNAL(clicked()), this, SLOT(previousrProc()));
    connect(m_nextBtn, SIGNAL(clicked()), this, SLOT(nextProc()));

}

void addressBook::updateInterface(addressBook::nodeType t_nodeType)
{
    m_currentType = t_nodeType;

    switch(m_currentType)
    {
        case EDIT_NODE:
        case ADD_NODE:
        {
            //save previous information
            m_oldInfo.m_name = m_nameEdit->text();
            m_oldInfo.m_address = m_addressEdit->toPlainText();

            m_nameEdit->setReadOnly(false);
            m_addressEdit->setReadOnly(false);

            m_submitBtn->show();
            m_cancelBtn->show();

            m_addBtn->setDisabled(true);
            m_editBtn->setDisabled(true);
            m_removeBtn->setDisabled(true);

            //when m_infoMap > 2, the findButton is enable
            m_findBtn->setEnabled(m_infoMap.size() > 2);
            m_submitBtn->setDisabled(false);
            m_cancelBtn->setDisabled(false);
            m_loadBtn->setDisabled(true);
            m_saveBtn->setDisabled(true);
            m_previousBtn->setDisabled(true);
            m_nextBtn->setDisabled(true);
        }
            break;
        case OTHER_NODE:
        {
            //set text edit readonly
            m_nameEdit->setReadOnly(true);
            m_addressEdit->setReadOnly(true);

            //set corssponding button
            int t_mapSize = m_infoMap.size();

            m_addBtn->setEnabled(true);
            m_editBtn->setEnabled(t_mapSize > 0);
            m_removeBtn->setEnabled(t_mapSize > 0);
            m_findBtn->setEnabled(t_mapSize > 2);
            m_loadBtn->setEnabled(true);
            m_saveBtn->setEnabled(t_mapSize > 0);
            m_previousBtn->setEnabled(t_mapSize > 1);
            m_nextBtn->setEnabled(t_mapSize > 1);

            //hide submit,cancel button
            m_submitBtn->hide();
            m_cancelBtn->hide();
        }
            break;
        default:
            qDebug() << "the node is not find";
    }
}

void addressBook::addProc()
{
    qDebug() << "addProc";

    updateInterface(ADD_NODE);

    //clear Edit
    m_nameEdit->clear();
    m_addressEdit->clear();

}

void addressBook::editProc()
{
    qDebug() << "editProc";

    updateInterface(EDIT_NODE);
}

void addressBook::removeProc()
{
    qDebug() << "removeProc";

    m_currentInfo.m_name = m_nameEdit->text();
    m_currentInfo.m_address = m_addressEdit->toPlainText();

    QMessageBox::StandardButton t_choiceBtn;

    t_choiceBtn = QMessageBox::information(this, "remove", "remove " + m_currentInfo.m_name + " ?",
                             QMessageBox::Yes | QMessageBox::No);

    if(QMessageBox::Yes == t_choiceBtn)
    {
        if(1 == m_infoMap.size())
        {
            m_infoMap.clear();

            QMessageBox::information(this, "remove seccessful", m_currentInfo.m_name + " is remove from addressbook");

            m_nameEdit->clear();
            m_addressEdit->clear();
        }
        else
        {
            previousrProc();

            m_infoMap.remove(m_currentInfo.m_name);

            QMessageBox::information(this, "remove seccessful", m_currentInfo.m_name + " is remove from addressbook");

        }
    }

    updateInterface(OTHER_NODE);

}

void addressBook::findProc()
{
    qDebug() << "findProc";

}

void addressBook::submitProc()
{
    qDebug() << "submitProc";

    //get text infomation
    m_currentInfo.m_name = m_nameEdit->text();
    m_currentInfo.m_address = m_addressEdit->toPlainText();

    //if text information is empty
    if(m_currentInfo.m_name.isEmpty() || m_currentInfo.m_address.isEmpty())
    {
        QMessageBox::information(this, "Empty filed", "please input name and andress", QMessageBox::Ok);
        return;
    }

    //last node is addbutton
    if(ADD_NODE == m_currentType)
    {
        //is the new name
        if(!m_infoMap.contains(m_currentInfo.m_name))
        {
            m_infoMap.insert(m_currentInfo.m_name, m_currentInfo.m_address);
            QMessageBox::information(this, "add successfull", m_currentInfo.m_name + " is add in the addressBook", QMessageBox::Ok);
        }
        else // the name has already exist
        {
            QMessageBox::information(this, "add failed", "sorry, " + m_currentInfo.m_name + " is already exist", QMessageBox::Ok);

            //put old information to text
            m_nameEdit->setText(m_oldInfo.m_name);
            m_addressEdit->setText(m_oldInfo.m_address);
        }
    }

    //lase node is editbutton
    if(EDIT_NODE == m_currentType)
    {
        //current infomation is not equal old infomation
        if(m_oldInfo.m_name != m_currentInfo.m_name || m_oldInfo.m_address != m_currentInfo.m_address)
        {
            if(m_infoMap.contains(m_currentInfo.m_name) && m_oldInfo.m_name != m_currentInfo.m_name)
            {
                QMessageBox::information(this, "edit failed", m_currentInfo.m_name + " is alread exist", QMessageBox::Ok);

                m_nameEdit->setText(m_oldInfo.m_name);
                m_addressEdit->setText(m_oldInfo.m_address);
            }
            else
            {
                m_infoMap.remove(m_oldInfo.m_name);

                m_infoMap.insert(m_currentInfo.m_name, m_currentInfo.m_address);

                QMessageBox::information(this, "edit successful", m_oldInfo.m_name + " is edit", QMessageBox::Ok);
            }
        }
    }

    updateInterface(OTHER_NODE);
}

void addressBook::cancelProc()
{
    qDebug() << "cancelProc";

    m_nameEdit->setText(m_oldInfo.m_name);
    m_addressEdit->setText(m_oldInfo.m_address);

    updateInterface(OTHER_NODE);
}

void addressBook::loadProc()
{
    qDebug() << "laodProc";

    m_fileName = QFileDialog::getOpenFileName(this, "open file", "", "TXT File(*.txt);;ALL File(*.*");


    if(m_fileName.isEmpty())
    {
//        QMessageBox::information(this, "Failed", "get file Nmae failed");
        return ;
    }

    QFile t_readFile(m_fileName);

    t_readFile.open(QIODevice::Text |QIODevice::ReadOnly);

    if(!t_readFile.isOpen())
    {
        return;
    }

    m_infoMap.clear();

    QTextStream t_textStream(& t_readFile);

    while(!t_textStream.atEnd())
    {
        QString t_lineInfo = t_textStream.readLine();

        m_infoMap.insert(t_lineInfo.split("\t")[0], t_lineInfo.split("\t")[1]);
    }

    t_readFile.close();

    m_nameEdit->setText(m_infoMap.begin().key());
    m_addressEdit->setText(m_infoMap.begin().value());

    updateInterface(OTHER_NODE);

//    t_read
}

void addressBook::saveProc()
{
    qDebug() << "saveProc";

    //get file name
    m_fileName = QFileDialog::getSaveFileName(this, "Save File", "", "TXT File(*.txt);;ALL File(*.*");

    //get file name failed
    if(m_fileName.isEmpty())
    {
//        QMessageBox::information(this, "Failed", "get file Nmae failed");
        return ;
    }

    QFile t_writeFile(m_fileName);

    //open file
    t_writeFile.open(QIODevice::Text | QIODevice::WriteOnly);

    //open failed
    if(!t_writeFile.isOpen())
    {
//        QMessageBox::information(this, "Fialed", "open " + m_fileName + " failed");
        return ;
    }

    QTextStream t_textStream(&t_writeFile);

    //write m_infoMap to file
    for (m_iter = m_infoMap.begin(); m_iter != m_infoMap.end(); m_iter++)
    {
        t_textStream << m_iter.key() << "\t" << m_iter.value() << "\n";
    }

    //close file
    t_writeFile.close();
}

void addressBook::previousrProc()
{
    qDebug() << "previousProc";

    //get text information
    m_currentInfo.m_name = m_nameEdit->text();
    m_currentInfo.m_address = m_addressEdit->toPlainText();

    m_iter = m_infoMap.find(m_currentInfo.m_name);

    if(m_iter == m_infoMap.begin())
    {
        m_iter = m_infoMap.end();
    }

    m_iter --;

    m_nameEdit->setText(m_iter.key());
    m_addressEdit->setText(m_iter.value());
}

void addressBook::nextProc()
{
    qDebug() << "nextProc";

    //get text information

    m_currentInfo.m_name = m_nameEdit->text();
    m_currentInfo.m_address = m_addressEdit->toPlainText();

    m_iter = m_infoMap.find(m_currentInfo.m_name);

    m_iter ++;
    if(m_iter == m_infoMap.end())
    {
        m_iter = m_infoMap.begin();
    }

    m_nameEdit->setText(m_iter.key());
    m_addressEdit->setText(m_iter.value());

}
