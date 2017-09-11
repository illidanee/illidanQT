/********************************************************************************
** Form generated from reading UI file 'XMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XMAINWINDOW_H
#define UI_XMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XMainWindow
{
public:

    void setupUi(QWidget *XMainWindow)
    {
        if (XMainWindow->objectName().isEmpty())
            XMainWindow->setObjectName(QStringLiteral("XMainWindow"));
        XMainWindow->resize(400, 300);

        retranslateUi(XMainWindow);

        QMetaObject::connectSlotsByName(XMainWindow);
    } // setupUi

    void retranslateUi(QWidget *XMainWindow)
    {
        XMainWindow->setWindowTitle(QApplication::translate("XMainWindow", "XMainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class XMainWindow: public Ui_XMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XMAINWINDOW_H
