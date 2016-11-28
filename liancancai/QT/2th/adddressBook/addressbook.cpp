#include "addressbook.h"

addressBook::addressBook(QWidget *parent)
    : QMainWindow(parent),
    m_gLayout(0), m_vLayout(0), m_hLayout(0),
    m_nameLabel(0), m_addressLabel(0),
    m_nameEdit(0), m_addressEdit(0),
    m_addBtn(0), m_editBtn(0), m_removeBtn(0),
    m_findBtn(0), m_submitBtn(0), m_cancelBtn(0),
    m_loadBtn(0), m_saveBtn(0), m_previousBtn(0),
    m_nextBtn(0)

{
    createInterface();
}

addressBook::~addressBook()
{

}

void addressBook::createInterface()
{
    m_gLayout = new QGridLayout;
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
    m_previousBtn = new QPushButton("Previsour", this);
    m_nextBtn = new QPushButton("Next", this);


    m_vLayout->addWidget(m_addBtn);
    m_vLayout->addWidget(m_editBtn);
    m_vLayout->addWidget(m_removeBtn);
    m_vLayout->addWidget(m_findBtn);
    m_vLayout->addWidget(m_submitBtn);
    m_vLayout->addWidget(m_cancelBtn);
    m_vLayout->addWidget(m_loadBtn);
    m_vLayout->addWidget(m_saveBtn);

    m_hLayout->addWidget(m_previousBtn);
    m_hLayout->addWidget(m_nextBtn);

    m_gLayout->addWidget(m_nameLabel, 0, 0);
    m_gLayout->addWidget(m_nameEdit, 0, 1);
    m_gLayout->addWidget(m_addressLabel, 1, 0);
    m_gLayout->addWidget(m_addressEdit, 1, 1);
    m_gLayout->addLayout(m_vLayout, 1 ,2);
    m_gLayout->addLayout(m_hLayout, 2, 1);

      this->setWindowTitle("123123123");

}

