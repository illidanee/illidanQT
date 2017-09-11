#pragma once

#include <QWidget>
#include "ui_XMainWindow.h"

class XMainWindow : public QWidget
{
	Q_OBJECT

public:
	XMainWindow(QWidget *parent = Q_NULLPTR);
	~XMainWindow();

private:
	Ui::XMainWindow ui;
};
