#pragma once

#include <QWidget>
#include "ui_XPasswordLineEdit.h"

class XPasswordLineEdit : public QWidget
{
	Q_OBJECT

public:
	XPasswordLineEdit(QWidget *parent = Q_NULLPTR);
	~XPasswordLineEdit();

private:
	Ui::XPasswordLineEdit ui;
};
