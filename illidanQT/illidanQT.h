#pragma once

#include <QtWidgets/QWidget>
#include "ui_illidanQT.h"

#include <QtGui>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QDesktopWidget>



class illidanQT : public QWidget
{
	Q_OBJECT

public:
	illidanQT(QWidget *parent = Q_NULLPTR);

private:
	virtual void closeEvent(QCloseEvent *event);
	virtual void paintEvent(QPaintEvent *event);

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);

private slots:
	void OnActivated(QSystemTrayIcon::ActivationReason reason);
	void OnMin();
	void OnExit();
	void OnLogin();

private:
	Ui::illidanQTClass ui;

	//拖动窗口
	bool m_RightButtonDown;
	QPoint m_OriginMousePos;
	QPoint m_OriginWindowPos;

	//系统托盘图标
	QSystemTrayIcon m_SystemTray;
};
