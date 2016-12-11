/********************************************************************************
** Form generated from reading UI file 'p17.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_P17_H
#define UI_P17_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_P17
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *P17)
    {
        if (P17->objectName().isEmpty())
            P17->setObjectName(QStringLiteral("P17"));
        P17->resize(400, 300);
        menuBar = new QMenuBar(P17);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        P17->setMenuBar(menuBar);
        mainToolBar = new QToolBar(P17);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        P17->addToolBar(mainToolBar);
        centralWidget = new QWidget(P17);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        P17->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(P17);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        P17->setStatusBar(statusBar);

        retranslateUi(P17);

        QMetaObject::connectSlotsByName(P17);
    } // setupUi

    void retranslateUi(QMainWindow *P17)
    {
        P17->setWindowTitle(QApplication::translate("P17", "P17", 0));
    } // retranslateUi

};

namespace Ui {
    class P17: public Ui_P17 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_P17_H
