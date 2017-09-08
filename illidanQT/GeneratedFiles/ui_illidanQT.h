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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "xpasswordlineedit.h"
#include "xusernamelineedit.h"

QT_BEGIN_NAMESPACE

class Ui_illidanQTClass
{
public:
    QAction *actionPower;
    QAction *actionSettings;
    QAction *actionDebug;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *BtnMin;
    QToolButton *BtnClose;
    QSpacerItem *verticalSpacer;
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
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *illidanQTClass)
    {
        if (illidanQTClass->objectName().isEmpty())
            illidanQTClass->setObjectName(QStringLiteral("illidanQTClass"));
        illidanQTClass->resize(805, 710);
        actionPower = new QAction(illidanQTClass);
        actionPower->setObjectName(QStringLiteral("actionPower"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Sys/Resources/Power.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPower->setIcon(icon);
        actionSettings = new QAction(illidanQTClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Sys/Resources/Settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon1);
        actionDebug = new QAction(illidanQTClass);
        actionDebug->setObjectName(QStringLiteral("actionDebug"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Sys/Resources/Debug.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDebug->setIcon(icon2);
        verticalLayout = new QVBoxLayout(illidanQTClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(668, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        BtnMin = new QToolButton(illidanQTClass);
        BtnMin->setObjectName(QStringLiteral("BtnMin"));
        BtnMin->setMinimumSize(QSize(32, 32));
        BtnMin->setMaximumSize(QSize(32, 32));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Sys/Resources/Min.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnMin->setIcon(icon3);
        BtnMin->setIconSize(QSize(32, 32));
        BtnMin->setAutoRaise(true);

        horizontalLayout->addWidget(BtnMin);

        BtnClose = new QToolButton(illidanQTClass);
        BtnClose->setObjectName(QStringLiteral("BtnClose"));
        BtnClose->setMinimumSize(QSize(32, 32));
        BtnClose->setMaximumSize(QSize(32, 32));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Sys/Resources/Close.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnClose->setIcon(icon4);
        BtnClose->setIconSize(QSize(32, 32));
        BtnClose->setAutoRaise(true);

        horizontalLayout->addWidget(BtnClose);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 360, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
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
        horizontalLayout_3->setSpacing(6);
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
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        pushButton = new QPushButton(illidanQTClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(100, 50));
        pushButton->setAutoDefault(false);

        horizontalLayout_4->addWidget(pushButton);

        horizontalSpacer_8 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        pushButton_2 = new QPushButton(illidanQTClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(100, 50));

        horizontalLayout_4->addWidget(pushButton_2);

        horizontalSpacer_7 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_4 = new QSpacerItem(20, 169, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        retranslateUi(illidanQTClass);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(illidanQTClass);
    } // setupUi

    void retranslateUi(QWidget *illidanQTClass)
    {
        illidanQTClass->setWindowTitle(QApplication::translate("illidanQTClass", "illidanQT", 0));
        actionPower->setText(QApplication::translate("illidanQTClass", "\351\200\200\345\207\272", 0));
        actionSettings->setText(QApplication::translate("illidanQTClass", "\350\256\276\347\275\256", 0));
        actionDebug->setText(QApplication::translate("illidanQTClass", "\345\267\245\345\205\267", 0));
        BtnMin->setText(QString());
        BtnClose->setText(QString());
        pushButton->setText(QApplication::translate("illidanQTClass", "Login", 0));
        pushButton->setShortcut(QApplication::translate("illidanQTClass", "Return", 0));
        pushButton_2->setText(QApplication::translate("illidanQTClass", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class illidanQTClass: public Ui_illidanQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ILLIDANQT_H
