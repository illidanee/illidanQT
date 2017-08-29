/********************************************************************************
** Form generated from reading UI file 'illidanQT.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ILLIDANQT_H
#define UI_ILLIDANQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <xbutton.h>

QT_BEGIN_NAMESPACE

class Ui_illidanQTClass
{
public:
    QAction *actionExit;
    QAction *actionSettings;
    QAction *actionTools;
    XButton *BtnMinimize;

    void setupUi(QWidget *illidanQTClass)
    {
        if (illidanQTClass->objectName().isEmpty())
            illidanQTClass->setObjectName(QStringLiteral("illidanQTClass"));
        illidanQTClass->resize(483, 674);
        actionExit = new QAction(illidanQTClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Sys/Resources/SignOut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        actionSettings = new QAction(illidanQTClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Sys/Resources/Settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon1);
        actionTools = new QAction(illidanQTClass);
        actionTools->setObjectName(QStringLiteral("actionTools"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Sys/Resources/Tools.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTools->setIcon(icon2);
        BtnMinimize = new XButton(illidanQTClass);
        BtnMinimize->setObjectName(QStringLiteral("BtnMinimize"));
        BtnMinimize->setGeometry(QRect(417, 3, 64, 64));

        retranslateUi(illidanQTClass);

        QMetaObject::connectSlotsByName(illidanQTClass);
    } // setupUi

    void retranslateUi(QWidget *illidanQTClass)
    {
        illidanQTClass->setWindowTitle(QApplication::translate("illidanQTClass", "illidanQT", 0));
        actionExit->setText(QApplication::translate("illidanQTClass", "\351\200\200\345\207\272", 0));
        actionSettings->setText(QApplication::translate("illidanQTClass", "\350\256\276\347\275\256", 0));
        actionTools->setText(QApplication::translate("illidanQTClass", "\345\267\245\345\205\267", 0));
    } // retranslateUi

};

namespace Ui {
    class illidanQTClass: public Ui_illidanQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ILLIDANQT_H
