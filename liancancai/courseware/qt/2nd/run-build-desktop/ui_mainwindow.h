/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Nov 25 11:40:02 2016
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *cmdLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *openLabel;
    QLineEdit *cmdLineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QPushButton *browserButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(328, 184);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cmdLabel = new QLabel(centralWidget);
        cmdLabel->setObjectName(QString::fromUtf8("cmdLabel"));

        verticalLayout->addWidget(cmdLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        openLabel = new QLabel(centralWidget);
        openLabel->setObjectName(QString::fromUtf8("openLabel"));

        horizontalLayout_2->addWidget(openLabel);

        cmdLineEdit = new QLineEdit(centralWidget);
        cmdLineEdit->setObjectName(QString::fromUtf8("cmdLineEdit"));

        horizontalLayout_2->addWidget(cmdLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        submitButton = new QPushButton(centralWidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));

        horizontalLayout->addWidget(submitButton);

        cancelButton = new QPushButton(centralWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        browserButton = new QPushButton(centralWidget);
        browserButton->setObjectName(QString::fromUtf8("browserButton"));

        horizontalLayout->addWidget(browserButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 328, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        cmdLabel->setText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\277\220\350\241\214\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        openLabel->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\357\274\232", 0, QApplication::UnicodeUTF8));
        submitButton->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        browserButton->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
