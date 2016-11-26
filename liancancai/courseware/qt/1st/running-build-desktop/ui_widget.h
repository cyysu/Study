/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Fri Nov 25 11:33:22 2016
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *cmdLabel;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *openLabel;
    QLineEdit *cmdLineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *submitButton;
    QPushButton *cancelBUtton;
    QPushButton *browserButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setMinimumSize(QSize(0, 0));
        Widget->setMaximumSize(QSize(800, 600));
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cmdLabel = new QLabel(Widget);
        cmdLabel->setObjectName(QString::fromUtf8("cmdLabel"));

        verticalLayout_2->addWidget(cmdLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        openLabel = new QLabel(Widget);
        openLabel->setObjectName(QString::fromUtf8("openLabel"));

        horizontalLayout_2->addWidget(openLabel);

        cmdLineEdit = new QLineEdit(Widget);
        cmdLineEdit->setObjectName(QString::fromUtf8("cmdLineEdit"));

        horizontalLayout_2->addWidget(cmdLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        submitButton = new QPushButton(Widget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));

        horizontalLayout->addWidget(submitButton);

        cancelBUtton = new QPushButton(Widget);
        cancelBUtton->setObjectName(QString::fromUtf8("cancelBUtton"));

        horizontalLayout->addWidget(cancelBUtton);

        browserButton = new QPushButton(Widget);
        browserButton->setObjectName(QString::fromUtf8("browserButton"));

        horizontalLayout->addWidget(browserButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        cmdLabel->setText(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; color:#0055ff;\">\350\257\267\350\276\223\345\205\245\345\221\275\344\273\244\357\274\232</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        openLabel->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\357\274\232", 0, QApplication::UnicodeUTF8));
        submitButton->setText(QApplication::translate("Widget", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        cancelBUtton->setText(QApplication::translate("Widget", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        browserButton->setText(QApplication::translate("Widget", "\346\265\217\350\247\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
