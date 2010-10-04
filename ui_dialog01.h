/********************************************************************************
** Form generated from reading UI file 'dialog01.ui'
**
** Created: Sat Aug 21 15:29:38 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG01_H
#define UI_DIALOG01_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog01
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Dialog01)
    {
        if (Dialog01->objectName().isEmpty())
            Dialog01->setObjectName(QString::fromUtf8("Dialog01"));
        Dialog01->resize(242, 148);
        verticalLayoutWidget = new QWidget(Dialog01);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 221, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(Dialog01);

        QMetaObject::connectSlotsByName(Dialog01);
    } // setupUi

    void retranslateUi(QWidget *Dialog01)
    {
        Dialog01->setWindowTitle(QApplication::translate("Dialog01", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog01", "blaa", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog01", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog01: public Ui_Dialog01 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG01_H
