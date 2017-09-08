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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(illidanQTClass);

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
    } // retranslateUi

};

namespace Ui {
    class illidanQTClass: public Ui_illidanQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ILLIDANQT_H
