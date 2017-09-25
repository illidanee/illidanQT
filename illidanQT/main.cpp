#include "XLogin.h"
#include "XMainWindow.h"
#include "./OpenGL/XOpenGLWindow.h"
#include <QtWidgets/QApplication>

#include <QFile>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//��ǰĿ¼
	QDir dir;
	qDebug() << "------ Start : Current Program Dir is = " << dir.currentPath() << endl;

	//���÷�� - ��ȡ�ļ�����ΪUTF-8,������Ҫת�롣
	QFile styleSheet("app.css");
	styleSheet.open(QIODevice::ReadOnly);
	QString typle = styleSheet.readAll();
	a.setStyleSheet(typle);

	//����OpenGL�İ汾��Ϣ
	QSurfaceFormat format;
	format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
	format.setRenderableType(QSurfaceFormat::OpenGL);
	format.setProfile(QSurfaceFormat::CoreProfile);
	format.setVersion(3, 3);
	format.setDepthBufferSize(24);
	format.setStencilBufferSize(8);
	format.setSamples(8);
	QSurfaceFormat::setDefaultFormat(format);

	XOpenGLWindow xOpenGLWindow;
	XLogin xLogin;

	//int res = xLogin.exec();
	//if (res == QDialog::Accepted)
	//{
		//xOpenGLWindow.showFullScreen();
		xOpenGLWindow.setFixedSize(1280, 800);
		xOpenGLWindow.show();
		return a.exec();
	//}
	
	return 0;
}
