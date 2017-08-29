#include "XButton.h"

XButton::XButton(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	m_RightButtonDown = false;

	//���ر���ͼƬ
	m_NBG.load(":/Menu/Resources/BTN1.png");
	m_PBG.load(":/Menu/Resources/BTN2.png");

	//���ô����ޱ߿�
	setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

	//���ô�������͸��
	setAttribute(Qt::WA_TranslucentBackground);

	//���ô��ڴ�С
	//setFixedSize(QSize(32, 32));
}

XButton::~XButton()
{
}

void XButton::paintEvent(QPaintEvent *event)
{
	QWidget::paintEvent(event);

	//���Ʊ���ͼƬ
	QPainter painter(this);

	if (m_RightButtonDown)
		painter.drawPixmap(this->rect(), m_PBG);
	else
		painter.drawPixmap(this->rect(), m_NBG);
	

}

void XButton::mousePressEvent(QMouseEvent *event)
{
	QWidget::mousePressEvent(event);

	if (Qt::LeftButton & event->button())
	{
		m_RightButtonDown = true;
		update();
	}
}

void XButton::mouseReleaseEvent(QMouseEvent *event)
{
	QWidget::mousePressEvent(event);

	if (Qt::LeftButton & event->button())
	{
		emit LiftButtonUp(event);

		m_RightButtonDown = false;
		update();
	}
}