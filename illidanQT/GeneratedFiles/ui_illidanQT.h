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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "xloginbutton.h"
#include "xpasswordlineedit.h"
#include "xusernamelineedit.h"

QT_BEGIN_NAMESPACE

class Ui_illidanQTClass
{
public:
    QAction *actionExit;
    QAction *actionSettings;
    QAction *actionTools;
    QAction *actionInfo;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *BtnMin;
    QToolButton *BtnClose;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    QLabel *Name;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    XUserNameLineEdit *widget_3;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    XPasswordLineEdit *widget_4;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    XLoginButton *widget;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *illidanQTClass)
    {
        if (illidanQTClass->objectName().isEmpty())
            illidanQTClass->setObjectName(QStringLiteral("illidanQTClass"));
        illidanQTClass->resize(1117, 919);
        actionExit = new QAction(illidanQTClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Sys/Resources/Close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        actionSettings = new QAction(illidanQTClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Sys/Resources/Settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon1);
        actionTools = new QAction(illidanQTClass);
        actionTools->setObjectName(QStringLiteral("actionTools"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Sys/Resources/More.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTools->setIcon(icon2);
        actionInfo = new QAction(illidanQTClass);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Sys/Resources/Admin.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInfo->setIcon(icon3);
        verticalLayout = new QVBoxLayout(illidanQTClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(668, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        BtnMin = new QToolButton(illidanQTClass);
        BtnMin->setObjectName(QStringLiteral("BtnMin"));
        BtnMin->setMinimumSize(QSize(32, 32));
        BtnMin->setMaximumSize(QSize(32, 32));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Sys/Resources/Min.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnMin->setIcon(icon4);
        BtnMin->setIconSize(QSize(32, 32));
        BtnMin->setAutoRaise(true);

        horizontalLayout->addWidget(BtnMin);

        BtnClose = new QToolButton(illidanQTClass);
        BtnClose->setObjectName(QStringLiteral("BtnClose"));
        BtnClose->setMinimumSize(QSize(32, 32));
        BtnClose->setMaximumSize(QSize(32, 32));
        BtnClose->setIcon(icon);
        BtnClose->setIconSize(QSize(32, 32));
        BtnClose->setAutoRaise(true);

        horizontalLayout->addWidget(BtnClose);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 320, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        Name = new QLabel(illidanQTClass);
        Name->setObjectName(QStringLiteral("Name"));
        Name->setMinimumSize(QSize(235, 70));
        Name->setMaximumSize(QSize(235, 70));
        Name->setAutoFillBackground(true);
        Name->setScaledContents(true);
        Name->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(Name);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 144, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(16);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        widget_3 = new XUserNameLineEdit(illidanQTClass);
        widget_3->setObjectName(QStringLiteral("widget_3"));

        horizontalLayout_2->addWidget(widget_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(16);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        widget_4 = new XPasswordLineEdit(illidanQTClass);
        widget_4->setObjectName(QStringLiteral("widget_4"));

        horizontalLayout_3->addWidget(widget_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(16);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        widget = new XLoginButton(illidanQTClass);
        widget->setObjectName(QStringLiteral("widget"));

        horizontalLayout_4->addWidget(widget);

        horizontalSpacer_7 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_4 = new QSpacerItem(20, 220, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        retranslateUi(illidanQTClass);

        QMetaObject::connectSlotsByName(illidanQTClass);
    } // setupUi

    void retranslateUi(QWidget *illidanQTClass)
    {
        illidanQTClass->setWindowTitle(QApplication::translate("illidanQTClass", "illidanQT", 0));
        actionExit->setText(QApplication::translate("illidanQTClass", "\351\200\200\345\207\272", 0));
        actionSettings->setText(QApplication::translate("illidanQTClass", "\350\256\276\347\275\256", 0));
        actionTools->setText(QApplication::translate("illidanQTClass", "\345\267\245\345\205\267", 0));
        actionInfo->setText(QApplication::translate("illidanQTClass", "\344\277\241\346\201\257", 0));
        BtnMin->setText(QString());
        BtnClose->setText(QString());
        Name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class illidanQTClass: public Ui_illidanQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ILLIDANQT_H
