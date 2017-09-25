#include "XLogin.h"
#include "XMainWindow.h"
#include "./OpenGL/XOpenGLWindow.h"
#include <QtWidgets/QApplication>

#include <QFile>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//当前目录
	QDir dir;
	qDebug() << "------ Start : Current Program Dir is = " << dir.currentPath() << endl;

	//设置风格 - 读取文件编码为UTF-8,否则需要转码。
	QFile styleSheet("app.css");
	styleSheet.open(QIODevice::ReadOnly);
	QString typle = styleSheet.readAll();
	a.setStyleSheet(typle);

	//设置OpenGL的版本信息
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
