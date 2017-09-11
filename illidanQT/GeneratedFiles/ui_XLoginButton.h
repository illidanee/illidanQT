/********************************************************************************
** Form generated from reading UI file 'XLoginButton.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XLOGINBUTTON_H
#define UI_XLOGINBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XLoginButton
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *LoginPageBtnLogin;

    void setupUi(QWidget *XLoginButton)
    {
        if (XLoginButton->objectName().isEmpty())
            XLoginButton->setObjectName(QStringLiteral("XLoginButton"));
        XLoginButton->resize(300, 68);
        XLoginButton->setMinimumSize(QSize(300, 68));
        XLoginButton->setMaximumSize(QSize(300, 68));
        horizontalLayout = new QHBoxLayout(XLoginButton);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        LoginPageBtnLogin = new QPushButton(XLoginButton);
        LoginPageBtnLogin->setObjectName(QStringLiteral("LoginPageBtnLogin"));
        LoginPageBtnLogin->setMinimumSize(QSize(300, 68));
        LoginPageBtnLogin->setMaximumSize(QSize(300, 68));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        LoginPageBtnLogin->setFont(font);
        LoginPageBtnLogin->setAutoDefault(false);
        LoginPageBtnLogin->setFlat(true);

        horizontalLayout->addWidget(LoginPageBtnLogin);


        retranslateUi(XLoginButton);

        LoginPageBtnLogin->setDefault(false);


        QMetaObject::connectSlotsByName(XLoginButton);
    } // setupUi

    void retranslateUi(QWidget *XLoginButton)
    {
        XLoginButton->setWindowTitle(QApplication::translate("XLoginButton", "XLoginButton", 0));
        LoginPageBtnLogin->setText(QApplication::translate("XLoginButton", "Lign In", 0));
        LoginPageBtnLogin->setShortcut(QApplication::translate("XLoginButton", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class XLoginButton: public Ui_XLoginButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XLOGINBUTTON_H
