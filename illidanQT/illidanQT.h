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
	int OnExit(bool checked);
	int OnActivated(QSystemTrayIcon::ActivationReason reason);

private:
	Ui::illidanQTClass ui;

	//����
	QPixmap m_BG;

	//�϶�����
	bool m_RightButtonDown;
	QPoint m_OriginMousePos;
	QPoint m_OriginWindowPos;

	//ϵͳ����ͼ��
	QSystemTrayIcon m_SystemTray;
};
