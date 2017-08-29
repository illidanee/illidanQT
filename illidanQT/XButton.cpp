#include "XButton.h"

XButton::XButton(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	m_RightButtonDown = false;

	//¼ÓÔØ±³¾°Í¼Æ¬
	m_NBG.load(":/Menu/Resources/BTN1.png");
	m_PBG.load(":/Menu/Resources/BTN2.png");

	//ÉèÖÃ´°¿ÚÎÞ±ß¿ò
	setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

	//ÉèÖÃ´°¿ÚÊôÐÔÍ¸Ã÷
	setAttribute(Qt::WA_TranslucentBackground);

	//ÉèÖÃ´°¿Ú´óÐ¡
	//setFixedSize(QSize(32, 32));
}

XButton::~XButton()
{
}

void XButton::paintEvent(QPaintEvent *event)
{
	QWidget::paintEvent(event);

	//»æÖÆ±³¾°Í¼Æ¬
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