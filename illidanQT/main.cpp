#include "illidanQT.h"
#include <QtWidgets/QApplication>

#include <QFile>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//设置风格 - 读取文件编码为UTF-8,否则需要转码。
	QFile styleSheet("app.css");
	styleSheet.open(QIODevice::ReadOnly);
	QString typle = styleSheet.readAll();
	a.setStyleSheet(typle);

	illidanQT w;
	w.show();
	return a.exec();
}
