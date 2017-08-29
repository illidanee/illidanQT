#pragma once

#include <QWidget>
#include "ui_XButton.h"

#include <QtGui>

class XButton : public QWidget
{
	Q_OBJECT

public:
	XButton(QWidget *parent = Q_NULLPTR);
	~XButton();

private:
	virtual void paintEvent(QPaintEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

signals:
	void LiftButtonUp(QMouseEvent *event);

private:
	Ui::XButton ui;

	bool m_RightButtonDown;
	//±³¾°
	QPixmap m_NBG;
	QPixmap m_PBG;
};
