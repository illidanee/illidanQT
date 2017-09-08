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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XUserNameLineEdit
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBoxBG;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *EditUserName;
    QLabel *label;

    void setupUi(QWidget *XUserNameLineEdit)
    {
        if (XUserNameLineEdit->objectName().isEmpty())
            XUserNameLineEdit->setObjectName(QStringLiteral("XUserNameLineEdit"));
        XUserNameLineEdit->resize(300, 50);
        XUserNameLineEdit->setMinimumSize(QSize(300, 50));
        XUserNameLineEdit->setMaximumSize(QSize(300, 50));
        horizontalLayout_2 = new QHBoxLayout(XUserNameLineEdit);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBoxBG = new QGroupBox(XUserNameLineEdit);
        groupBoxBG->setObjectName(QStringLiteral("groupBoxBG"));
        horizontalLayout_3 = new QHBoxLayout(groupBoxBG);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        EditUserName = new QLineEdit(groupBoxBG);
        EditUserName->setObjectName(QStringLiteral("EditUserName"));
        EditUserName->setMinimumSize(QSize(200, 40));
        EditUserName->setMaximumSize(QSize(300, 40));
        QFont font;
        font.setPointSize(16);
        EditUserName->setFont(font);
        EditUserName->setFrame(false);

        horizontalLayout->addWidget(EditUserName);

        label = new QLabel(groupBoxBG);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/LoginPage/Resources/user.png")));
        label->setMargin(10);

        horizontalLayout->addWidget(label);


        horizontalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(groupBoxBG);


        retranslateUi(XUserNameLineEdit);

        QMetaObject::connectSlotsByName(XUserNameLineEdit);
    } // setupUi

    void retranslateUi(QWidget *XUserNameLineEdit)
    {
        XUserNameLineEdit->setWindowTitle(QApplication::translate("XUserNameLineEdit", "XUserNameLineEdit", 0));
        EditUserName->setPlaceholderText(QApplication::translate("XUserNameLineEdit", "\347\224\250\346\210\267\345\220\215", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class XUserNameLineEdit: public Ui_XUserNameLineEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XUSERNAMELINEEDIT_H
