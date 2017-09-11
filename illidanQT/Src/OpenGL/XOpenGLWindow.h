#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>

#include "Manager.h"


class XOpenGLWindow : public QOpenGLWidget
{
	Q_OBJECT

public:
	XOpenGLWindow(QWidget *parent = 0);
	~XOpenGLWindow();

	//绘制
	virtual void initializeGL();
	virtual void resizeGL(int width, int height);
	virtual void paintGL();

	//鼠标事件
	virtual void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	virtual void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	virtual void mouseDoubleClickEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	virtual void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
#ifndef QT_NO_WHEELEVENT
	virtual void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
#endif

	//键盘事件
	virtual void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
	virtual void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
	
private:
	bool m_bFullScreen;
	int m_Width;
	int m_Height;
private:
	int m_TimerID;
	virtual void timerEvent(QTimerEvent * event) Q_DECL_OVERRIDE;
private:
	int m_LastMouseX;
	int m_LastMouseY;

private:
	std::vector<std::string> g_FaceTexture;

	GLuint m_Texture;

	GLuint m_Program;
	GLuint m_VAO;
	GLuint m_VBO;
};

#endif // RENDERWIDGET_H
