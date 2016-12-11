/********************************************************************************
** Form generated from reading UI file 'run.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUN_H
#define UI_RUN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_run
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *lablePlease;
    QTextEdit *cmdTextEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *sureButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QMenuBar *menuBar;
    QMenu *menuRun;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *run)
    {
        if (run->objectName().isEmpty())
            run->setObjectName(QStringLiteral("run"));
        run->resize(364, 200);
        centralWidget = new QWidget(run);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 20, 261, 81));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lablePlease = new QLabel(widget);
        lablePlease->setObjectName(QStringLiteral("lablePlease"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        lablePlease->setFont(font);

        verticalLayout->addWidget(lablePlease);

        cmdTextEdit = new QTextEdit(widget);
        cmdTextEdit->setObjectName(QStringLiteral("cmdTextEdit"));

        verticalLayout->addWidget(cmdTextEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sureButton = new QPushButton(widget);
        sureButton->setObjectName(QStringLiteral("sureButton"));

        horizontalLayout->addWidget(sureButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout);

        run->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(run);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 364, 20));
        menuRun = new QMenu(menuBar);
        menuRun->setObjectName(QStringLiteral("menuRun"));
        run->setMenuBar(menuBar);
        mainToolBar = new QToolBar(run);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        run->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(run);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        run->setStatusBar(statusBar);

        menuBar->addAction(menuRun->menuAction());

        retranslateUi(run);

        QMetaObject::connectSlotsByName(run);
    } // setupUi

    void retranslateUi(QMainWindow *run)
    {
        run->setWindowTitle(QApplication::translate("run", "run", 0));
        lablePlease->setText(QApplication::translate("run", "Please input cmd", 0));
        sureButton->setText(QApplication::translate("run", "sure", 0));
        cancelButton->setText(QApplication::translate("run", "cancel", 0));
        menuRun->setTitle(QApplication::translate("run", "run", 0));
    } // retranslateUi

};

namespace Ui {
    class run: public Ui_run {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUN_H
