/********************************************************************************
** Form generated from reading UI file 'XPasswordLineEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XPASSWORDLINEEDIT_H
#define UI_XPASSWORDLINEEDIT_H

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

class Ui_XPasswordLineEdit
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *LoginPageLabel;
    QLineEdit *LoginPagePassword;

    void setupUi(QWidget *XPasswordLineEdit)
    {
        if (XPasswordLineEdit->objectName().isEmpty())
            XPasswordLineEdit->setObjectName(QStringLiteral("XPasswordLineEdit"));
        XPasswordLineEdit->resize(364, 68);
        XPasswordLineEdit->setMinimumSize(QSize(364, 68));
        XPasswordLineEdit->setMaximumSize(QSize(364, 68));
        horizontalLayout = new QHBoxLayout(XPasswordLineEdit);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        LoginPageLabel = new QLabel(XPasswordLineEdit);
        LoginPageLabel->setObjectName(QStringLiteral("LoginPageLabel"));
        LoginPageLabel->setMinimumSize(QSize(64, 64));
        LoginPageLabel->setMaximumSize(QSize(64, 64));
        LoginPageLabel->setPixmap(QPixmap(QString::fromUtf8(":/LoginPage/Resources/Lock.png")));
        LoginPageLabel->setAlignment(Qt::AlignCenter);
        LoginPageLabel->setMargin(0);

        horizontalLayout->addWidget(LoginPageLabel);

        LoginPagePassword = new QLineEdit(XPasswordLineEdit);
        LoginPagePassword->setObjectName(QStringLiteral("LoginPagePassword"));
        LoginPagePassword->setMinimumSize(QSize(300, 64));
        LoginPagePassword->setMaximumSize(QSize(300, 64));
        QFont font;
        font.setPointSize(16);
        LoginPagePassword->setFont(font);
        LoginPagePassword->setFrame(false);
        LoginPagePassword->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(LoginPagePassword);


        retranslateUi(XPasswordLineEdit);

        QMetaObject::connectSlotsByName(XPasswordLineEdit);
    } // setupUi

    void retranslateUi(QWidget *XPasswordLineEdit)
    {
        XPasswordLineEdit->setWindowTitle(QApplication::translate("XPasswordLineEdit", "XPasswordLineEdit", 0));
        LoginPageLabel->setText(QString());
        LoginPagePassword->setPlaceholderText(QApplication::translate("XPasswordLineEdit", "******", 0));
    } // retranslateUi

};

namespace Ui {
    class XPasswordLineEdit: public Ui_XPasswordLineEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XPASSWORDLINEEDIT_H
