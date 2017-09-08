/********************************************************************************
** Form generated from reading UI file 'XUserNameLineEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XUSERNAMELINEEDIT_H
#define UI_XUSERNAMELINEEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XUserNameLineEdit
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *LoginPageLabel;
    QLineEdit *LoginPageEmail;

    void setupUi(QWidget *XUserNameLineEdit)
    {
        if (XUserNameLineEdit->objectName().isEmpty())
            XUserNameLineEdit->setObjectName(QStringLiteral("XUserNameLineEdit"));
        XUserNameLineEdit->resize(364, 68);
        XUserNameLineEdit->setMinimumSize(QSize(364, 68));
        XUserNameLineEdit->setMaximumSize(QSize(364, 68));
        XUserNameLineEdit->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(XUserNameLineEdit);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        LoginPageLabel = new QLabel(XUserNameLineEdit);
        LoginPageLabel->setObjectName(QStringLiteral("LoginPageLabel"));
        LoginPageLabel->setMinimumSize(QSize(64, 64));
        LoginPageLabel->setMaximumSize(QSize(64, 64));
        LoginPageLabel->setStyleSheet(QStringLiteral(""));
        LoginPageLabel->setPixmap(QPixmap(QString::fromUtf8(":/LoginPage/Resources/Mail.png")));
        LoginPageLabel->setAlignment(Qt::AlignCenter);
        LoginPageLabel->setMargin(0);

        horizontalLayout->addWidget(LoginPageLabel);

        LoginPageEmail = new QLineEdit(XUserNameLineEdit);
        LoginPageEmail->setObjectName(QStringLiteral("LoginPageEmail"));
        LoginPageEmail->setMinimumSize(QSize(300, 64));
        LoginPageEmail->setMaximumSize(QSize(300, 64));
        QFont font;
        font.setPointSize(16);
        LoginPageEmail->setFont(font);
        LoginPageEmail->setFrame(false);

        horizontalLayout->addWidget(LoginPageEmail);


        retranslateUi(XUserNameLineEdit);

        QMetaObject::connectSlotsByName(XUserNameLineEdit);
    } // setupUi

    void retranslateUi(QWidget *XUserNameLineEdit)
    {
        XUserNameLineEdit->setWindowTitle(QApplication::translate("XUserNameLineEdit", "XUserNameLineEdit", 0));
        LoginPageLabel->setText(QString());
        LoginPageEmail->setPlaceholderText(QApplication::translate("XUserNameLineEdit", "Email Address", 0));
    } // retranslateUi

};

namespace Ui {
    class XUserNameLineEdit: public Ui_XUserNameLineEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XUSERNAMELINEEDIT_H
