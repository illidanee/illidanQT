#include "XLoginButton.h"

XLoginButton::XLoginButton(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.LoginPageBtnLogin, SIGNAL(released()), this, SLOT(OnBtnRelease()));
}

XLoginButton::~XLoginButton()
{
}

void XLoginButton::OnBtnRelease()
{
	emit released();
}