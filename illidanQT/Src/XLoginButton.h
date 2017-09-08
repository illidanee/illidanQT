#pragma once

#include <QWidget>
#include "ui_XLoginButton.h"

class XLoginButton : public QWidget
{
	Q_OBJECT

public:
	XLoginButton(QWidget *parent = Q_NULLPTR);
	~XLoginButton();

private:
	Ui::XLoginButton ui;
};
