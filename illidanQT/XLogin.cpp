#include "XLogin.h"



XLogin::XLogin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//初始化
	m_RightButtonDown = false;

	//设置窗口无边框
	setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

	//设置窗口大小 - 按照窗口宽度保持 W / H = 2
	QDesktopWidget *deskWgt = QApplication::desktop();
	int deskWidth = deskWgt->availableGeometry().width();
	int deskHeigh = deskWgt->availableGeometry().height();
	setFixedSize(QSize(deskWidth * 4 / 5, deskWidth * 2 / 5));

	//设置系统托盘
	m_SystemTray.setToolTip("CopyRight by : illidan.org");
	m_SystemTray.setIcon(QIcon(":/illidanQT/illidanQT.ico"));

	QMenu* menu = new QMenu();
	menu->addAction(ui.actionInfo);
	menu->addAction(ui.actionTools);
	menu->addAction(ui.actionSettings);
	menu->addSeparator();
	menu->addAction(ui.actionExit);
	m_SystemTray.setContextMenu(menu);

	m_SystemTray.show();

	connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(OnExit()));
	connect(&m_SystemTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(OnActivated(QSystemTrayIcon::ActivationReason)));

	//关联其他事件
	connect(ui.BtnMin, SIGNAL(released()), this, SLOT(OnMin()));
	connect(ui.BtnClose, SIGNAL(released()), this, SLOT(OnExit()));

	//登陆事件
	connect(ui.PasswordWidget, SIGNAL(returnPressed()), this, SLOT(OnLogin()));
	connect(ui.LoginButtonWdiget, SIGNAL(released()), this, SLOT(OnLogin()));
}

void XLogin::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void XLogin::paintEvent(QPaintEvent *event)
{
	QWidget::paintEvent(event);
}

void XLogin::mousePressEvent(QMouseEvent *event)
{
	QWidget::mousePressEvent(event);

	if (Qt::RightButton & event->button())
	{
		//开始状态
		m_RightButtonDown = true;
		m_OriginMousePos = event->globalPos();
		m_OriginWindowPos = frameGeometry().topLeft();
	}
}

void XLogin::mouseReleaseEvent(QMouseEvent *event)
{
	QWidget::mouseReleaseEvent(event);

	if (Qt::RightButton & event->button())
	{
		//取消状态
		m_RightButtonDown = false;
	}
}

void XLogin::mouseMoveEvent(QMouseEvent *event)
{
	QWidget::mouseMoveEvent(event);

	if (m_RightButtonDown)
	{
		//移动状态
		QPoint deltaPos = event->globalPos() - m_OriginMousePos;
		move(m_OriginWindowPos + deltaPos);
	}
}

void XLogin::OnExit()
{
	QApplication::exit();
}

void XLogin::OnActivated(QSystemTrayIcon::ActivationReason reason)
{
	if (reason == QSystemTrayIcon::DoubleClick)
	{
		showNormal();
	}
}

void XLogin::OnMin()
{
	hide();
}

void XLogin::OnLogin()
{
	accept();
	qDebug() << "OnLogin......";
}