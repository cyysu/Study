/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Nov 28 16:47:39 2016
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
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newaction;
    QAction *openaction;
    QAction *saveaction;
    QAction *priaction;
    QAction *exitaction;
    QAction *undoaction;
    QAction *reaction;
    QAction *copy_t;
    QAction *pasteaction;
    QAction *cutaction;
    QAction *selectaction;
    QAction *action_3;
    QAction *action_4;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_E;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(303, 266);
        newaction = new QAction(MainWindow);
        newaction->setObjectName(QString::fromUtf8("newaction"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/actions/bookmark_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        newaction->setIcon(icon);
        openaction = new QAction(MainWindow);
        openaction->setObjectName(QString::fromUtf8("openaction"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/actions/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        openaction->setIcon(icon1);
        saveaction = new QAction(MainWindow);
        saveaction->setObjectName(QString::fromUtf8("saveaction"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/actions/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveaction->setIcon(icon2);
        priaction = new QAction(MainWindow);
        priaction->setObjectName(QString::fromUtf8("priaction"));
        exitaction = new QAction(MainWindow);
        exitaction->setObjectName(QString::fromUtf8("exitaction"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/actions/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitaction->setIcon(icon3);
        undoaction = new QAction(MainWindow);
        undoaction->setObjectName(QString::fromUtf8("undoaction"));
        reaction = new QAction(MainWindow);
        reaction->setObjectName(QString::fromUtf8("reaction"));
        copy_t = new QAction(MainWindow);
        copy_t->setObjectName(QString::fromUtf8("copy_t"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/actions/gtk-copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        copy_t->setIcon(icon4);
        pasteaction = new QAction(MainWindow);
        pasteaction->setObjectName(QString::fromUtf8("pasteaction"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/actions/gtk-paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        pasteaction->setIcon(icon5);
        cutaction = new QAction(MainWindow);
        cutaction->setObjectName(QString::fromUtf8("cutaction"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/actions/editcut.png"), QSize(), QIcon::Normal, QIcon::Off);
        cutaction->setIcon(icon6);
        selectaction = new QAction(MainWindow);
        selectaction->setObjectName(QString::fromUtf8("selectaction"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 303, 25));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QString::fromUtf8("menu_E"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menu_F->addAction(newaction);
        menu_F->addAction(openaction);
        menu_F->addAction(saveaction);
        menu_F->addSeparator();
        menu_F->addAction(priaction);
        menu_F->addAction(exitaction);
        menu_E->addAction(undoaction);
        menu_E->addAction(reaction);
        menu_E->addSeparator();
        menu_E->addAction(copy_t);
        menu_E->addAction(pasteaction);
        menu_E->addAction(cutaction);
        menu_E->addAction(selectaction);
        menu_E->addSeparator();
        menu_E->addAction(action_3);
        menu_E->addAction(action_4);
        mainToolBar->addAction(openaction);
        mainToolBar->addAction(exitaction);
        mainToolBar->addAction(copy_t);
        mainToolBar->addAction(pasteaction);
        mainToolBar->addAction(cutaction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        newaction->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", 0, QApplication::UnicodeUTF8));
        openaction->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", 0, QApplication::UnicodeUTF8));
        saveaction->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", 0, QApplication::UnicodeUTF8));
        priaction->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260(&P)", 0, QApplication::UnicodeUTF8));
        exitaction->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&E)", 0, QApplication::UnicodeUTF8));
        undoaction->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(&U)", 0, QApplication::UnicodeUTF8));
        reaction->setText(QApplication::translate("MainWindow", "\351\207\215\345\201\232(&R)", 0, QApplication::UnicodeUTF8));
        copy_t->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(&C)", 0, QApplication::UnicodeUTF8));
        copy_t->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        pasteaction->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(&P)", 0, QApplication::UnicodeUTF8));
        pasteaction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+W", 0, QApplication::UnicodeUTF8));
        cutaction->setText(QApplication::translate("MainWindow", "\345\211\252\350\264\264(&X)", 0, QApplication::UnicodeUTF8));
        selectaction->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211(&S)", 0, QApplication::UnicodeUTF8));
        action_3->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\255\227\344\275\223", 0, QApplication::UnicodeUTF8));
        action_4->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\351\242\234\350\211\262", 0, QApplication::UnicodeUTF8));
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0, QApplication::UnicodeUTF8));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
