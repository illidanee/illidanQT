#include "illidanQT.h"



illidanQT::illidanQT(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//初始化
	m_RightButtonDown = false;

	//--------------------------------------------------------------------------------
	//--		绘制普通图片背景

	////加载背景图片
	//m_BG.load(":/illidanQT/Resources/2048X1024.png");

	////设置窗口无边框
	//setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

	////设置窗口大小 - 按照窗口宽度保持 W / H = 2
	//QDesktopWidget *deskWgt = QApplication::desktop();
	//int deskWidth = deskWgt->availableGeometry().width();
	//int deskHeigh = deskWgt->availableGeometry().height();
	//setFixedSize(QSize(deskWidth * 4 / 5, deskWidth * 2 / 5));

	//--------------------------------------------------------------------------------
	//--		绘制透明图片背景

	//加载背景图片
	bool res = m_BG.load(":/illidanQT/Resources/BG.png");

	//设置窗口无边框
	setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

	//设置窗口属性透明
	setAttribute(Qt::WA_TranslucentBackground);

	//设置窗口大小
	resize(m_BG.size());

	//--------------------------------------------------------------------------------

	//设置系统托盘
	m_SystemTray.setToolTip("CopyRight by : illidan.org");
	m_SystemTray.setIcon(QIcon(":/illidanQT/illidanQT.ico"));

	QMenu* menu = new QMenu();
	menu->addAction(ui.actionTools);
	menu->addAction(ui.actionSettings);
	menu->addSeparator();
	menu->addAction(ui.actionExit);
	m_SystemTray.setContextMenu(menu);

	m_SystemTray.show();

	connect(&m_SystemTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(OnActivated(QSystemTrayIcon::ActivationReason)));

	//设置其他消息
	connect(ui.actionExit, SIGNAL(triggered(bool)), this, SLOT(OnExit(bool)));
}

void illidanQT::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void illidanQT::paintEvent(QPaintEvent *event)
{
	QWidget::paintEvent(event);

	//绘制背景图片
	QPainter painter(this);

	//--------------------------------------------------------------------------------
	//QRect rect = this->rect();
	//painter.drawPixmap(rect, m_BG);
	//--------------------------------------------------------------------------------
	painter.drawPixmap(0, 0, m_BG);
	//--------------------------------------------------------------------------------
}

void illidanQT::mousePressEvent(QMouseEvent *event)
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

void illidanQT::mouseReleaseEvent(QMouseEvent *event)
{
	QWidget::mouseReleaseEvent(event);

	if (Qt::RightButton & event->button())
	{
		//取消状态
		m_RightButtonDown = false;
	}
}

void illidanQT::mouseMoveEvent(QMouseEvent *event)
{
	QWidget::mouseMoveEvent(event);

	if (m_RightButtonDown)
	{
		//移动状态
		QPoint deltaPos = event->globalPos() - m_OriginMousePos;
		move(m_OriginWindowPos + deltaPos);
	}
}

int illidanQT::OnExit(bool checked)
{
	QApplication::exit();

	return 1;
}

int illidanQT::OnActivated(QSystemTrayIcon::ActivationReason reason)
{
	if (reason == QSystemTrayIcon::DoubleClick)
	{
		showNormal();
	}

	return 1;
}