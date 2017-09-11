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

	XOpenGLWindow xOpenGLWindow;
	XLogin xLogin;

	if (xLogin.exec() == QDialog::Accepted)
	{
		//xOpenGLWindow.showFullScreen();
		xOpenGLWindow.setFixedSize(1280, 800);
		xOpenGLWindow.show();
		return a.exec();
	}
	
	return 0;
}
