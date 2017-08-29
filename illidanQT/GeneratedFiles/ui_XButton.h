/********************************************************************************
** Form generated from reading UI file 'XButton.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XBUTTON_H
#define UI_XBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XButton
{
public:

    void setupUi(QWidget *XButton)
    {
        if (XButton->objectName().isEmpty())
            XButton->setObjectName(QStringLiteral("XButton"));
        XButton->resize(400, 300);

        retranslateUi(XButton);

        QMetaObject::connectSlotsByName(XButton);
    } // setupUi

    void retranslateUi(QWidget *XButton)
    {
        XButton->setWindowTitle(QApplication::translate("XButton", "XButton", 0));
    } // retranslateUi

};

namespace Ui {
    class XButton: public Ui_XButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XBUTTON_H
