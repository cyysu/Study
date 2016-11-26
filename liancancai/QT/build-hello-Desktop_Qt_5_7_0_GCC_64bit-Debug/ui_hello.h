/********************************************************************************
** Form generated from reading UI file 'hello.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLO_H
#define UI_HELLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hello
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *hello)
    {
        if (hello->objectName().isEmpty())
            hello->setObjectName(QStringLiteral("hello"));
        hello->resize(400, 300);
        QFont font;
        font.setPointSize(20);
        hello->setFont(font);
        centralWidget = new QWidget(hello);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 80, 161, 51));
        hello->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(hello);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 38));
        hello->setMenuBar(menuBar);
        mainToolBar = new QToolBar(hello);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        hello->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(hello);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        hello->setStatusBar(statusBar);

        retranslateUi(hello);

        QMetaObject::connectSlotsByName(hello);
    } // setupUi

    void retranslateUi(QMainWindow *hello)
    {
        hello->setWindowTitle(QApplication::translate("hello", "hello", 0));
        label->setText(QApplication::translate("hello", "helloworld", 0));
    } // retranslateUi

};

namespace Ui {
    class hello: public Ui_hello {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_H
