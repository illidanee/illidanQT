#include "XPasswordLineEdit.h"

XPasswordLineEdit::XPasswordLineEdit(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.LoginPagePassword, SIGNAL(returnPressed()), this, SLOT(OnReturnPressed()));
}

XPasswordLineEdit::~XPasswordLineEdit()
{
}

void XPasswordLineEdit::OnReturnPressed()
{
	emit returnPressed();
}
