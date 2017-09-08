#pragma once

#include <QWidget>
#include "ui_XUserNameLineEdit.h"

class XUserNameLineEdit : public QWidget
{
	Q_OBJECT

public:
	XUserNameLineEdit(QWidget *parent = Q_NULLPTR);
	~XUserNameLineEdit();

private:
	Ui::XUserNameLineEdit ui;
};
