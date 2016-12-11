/********************************************************************************
** Form generated from reading UI file 'addressbook.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRESSBOOK_H
#define UI_ADDRESSBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_addressBook
{
public:

    void setupUi(QDialog *addressBook)
    {
        if (addressBook->objectName().isEmpty())
            addressBook->setObjectName(QStringLiteral("addressBook"));
        addressBook->resize(400, 300);

        retranslateUi(addressBook);

        QMetaObject::connectSlotsByName(addressBook);
    } // setupUi

    void retranslateUi(QDialog *addressBook)
    {
        addressBook->setWindowTitle(QApplication::translate("addressBook", "addressBook", 0));
    } // retranslateUi

};

namespace Ui {
    class addressBook: public Ui_addressBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESSBOOK_H
