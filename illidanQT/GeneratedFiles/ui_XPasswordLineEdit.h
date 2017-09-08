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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XPasswordLineEdit
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBoxBG;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *EditPassword;
    QLabel *label;

    void setupUi(QWidget *XPasswordLineEdit)
    {
        if (XPasswordLineEdit->objectName().isEmpty())
            XPasswordLineEdit->setObjectName(QStringLiteral("XPasswordLineEdit"));
        XPasswordLineEdit->resize(300, 50);
        XPasswordLineEdit->setMinimumSize(QSize(300, 50));
        XPasswordLineEdit->setMaximumSize(QSize(300, 50));
        horizontalLayout_2 = new QHBoxLayout(XPasswordLineEdit);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBoxBG = new QGroupBox(XPasswordLineEdit);
        groupBoxBG->setObjectName(QStringLiteral("groupBoxBG"));
        horizontalLayout_3 = new QHBoxLayout(groupBoxBG);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        EditPassword = new QLineEdit(groupBoxBG);
        EditPassword->setObjectName(QStringLiteral("EditPassword"));
        EditPassword->setMinimumSize(QSize(200, 40));
        EditPassword->setMaximumSize(QSize(300, 40));
        QFont font;
        font.setPointSize(16);
        EditPassword->setFont(font);
        EditPassword->setFrame(false);
        EditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(EditPassword);

        label = new QLabel(groupBoxBG);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/LoginPage/Resources/pass-lock.png")));
        label->setMargin(10);

        horizontalLayout->addWidget(label);


        horizontalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(groupBoxBG);


        retranslateUi(XPasswordLineEdit);

        QMetaObject::connectSlotsByName(XPasswordLineEdit);
    } // setupUi

    void retranslateUi(QWidget *XPasswordLineEdit)
    {
        XPasswordLineEdit->setWindowTitle(QApplication::translate("XPasswordLineEdit", "XPasswordLineEdit", 0));
        EditPassword->setInputMask(QString());
        EditPassword->setPlaceholderText(QApplication::translate("XPasswordLineEdit", "\345\257\206\347\240\201", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class XPasswordLineEdit: public Ui_XPasswordLineEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XPASSWORDLINEEDIT_H
