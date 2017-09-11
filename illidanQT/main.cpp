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
