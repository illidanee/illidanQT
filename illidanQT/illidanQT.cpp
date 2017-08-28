#include "illidanQT.h"



illidanQT::illidanQT(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//��ʼ��
	m_RightButtonDown = false;

	//--------------------------------------------------------------------------------
	//--		������ͨͼƬ����

	////���ر���ͼƬ
	//m_BG.load(":/illidanQT/Resources/2048X1024.png");

	////���ô����ޱ߿�
	//setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

	////���ô��ڴ�С - ���մ��ڿ�ȱ��� W / H = 2
	//QDesktopWidget *deskWgt = QApplication::desktop();
	//int deskWidth = deskWgt->availableGeometry().width();
	//int deskHeigh = deskWgt->availableGeometry().height();
	//setFixedSize(QSize(deskWidth * 4 / 5, deskWidth * 2 / 5));

	//--------------------------------------------------------------------------------
	//--		����͸��ͼƬ����

	//���ر���ͼƬ
	bool res = m_BG.load(":/illidanQT/Resources/BG.png");

	//���ô����ޱ߿�
	setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

	//���ô�������͸��
	setAttribute(Qt::WA_TranslucentBackground);

	//���ô��ڴ�С
	resize(m_BG.size());

	//--------------------------------------------------------------------------------

	//����ϵͳ����
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

	//����������Ϣ
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

	//���Ʊ���ͼƬ
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
		//��ʼ״̬
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
		//ȡ��״̬
		m_RightButtonDown = false;
	}
}

void illidanQT::mouseMoveEvent(QMouseEvent *event)
{
	QWidget::mouseMoveEvent(event);

	if (m_RightButtonDown)
	{
		//�ƶ�״̬
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