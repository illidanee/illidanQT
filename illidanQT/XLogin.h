#pragma once

#include <QtWidgets/QDialog>
#include "ui_illidanQT.h"

#include <QtGui>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QDesktopWidget>



class XLogin : public QDialog
{
	Q_OBJECT

public:
	XLogin(QWidget *parent = Q_NULLPTR);

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

	//�϶�����
	bool m_RightButtonDown;
	QPoint m_OriginMousePos;
	QPoint m_OriginWindowPos;

	//ϵͳ����ͼ��
	QSystemTrayIcon m_SystemTray;
};
