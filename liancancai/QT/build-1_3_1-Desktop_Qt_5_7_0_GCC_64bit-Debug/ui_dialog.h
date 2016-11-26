/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_result
{
public:
    QPushButton *calculate;
    QLabel *result_2;
    QLabel *area;
    QLabel *radius;
    QTextEdit *input;

    void setupUi(QDialog *result)
    {
        if (result->objectName().isEmpty())
            result->setObjectName(QStringLiteral("result"));
        result->resize(522, 296);
        calculate = new QPushButton(result);
        calculate->setObjectName(QStringLiteral("calculate"));
        calculate->setGeometry(QRect(330, 190, 80, 23));
        result_2 = new QLabel(result);
        result_2->setObjectName(QStringLiteral("result_2"));
        result_2->setGeometry(QRect(348, 90, 121, 49));
        result_2->setFrameShape(QFrame::StyledPanel);
        result_2->setFrameShadow(QFrame::Sunken);
        area = new QLabel(result);
        area->setObjectName(QStringLiteral("area"));
        area->setGeometry(QRect(290, 80, 59, 70));
        radius = new QLabel(result);
        radius->setObjectName(QStringLiteral("radius"));
        radius->setGeometry(QRect(50, 80, 59, 70));
        input = new QTextEdit(result);
        input->setObjectName(QStringLiteral("input"));
        input->setGeometry(QRect(140, 100, 104, 31));

        retranslateUi(result);

        QMetaObject::connectSlotsByName(result);
    } // setupUi

    void retranslateUi(QDialog *result)
    {
        result->setWindowTitle(QApplication::translate("result", "Dialog", 0));
        calculate->setText(QApplication::translate("result", "calculate", 0));
        result_2->setText(QApplication::translate("result", "result_2", 0));
        area->setText(QApplication::translate("result", "area", 0));
        radius->setText(QApplication::translate("result", "radius", 0));
    } // retranslateUi

};

namespace Ui {
    class result: public Ui_result {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
