#include "illidanQT.h"
#include <QtWidgets/QApplication>

#include <QFile>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//���÷�� - ��ȡ�ļ�����ΪUTF-8,������Ҫת�롣
	QFile styleSheet("app.css");
	styleSheet.open(QIODevice::ReadOnly);
	QString typle = styleSheet.readAll();
	a.setStyleSheet(typle);

	illidanQT w;
	w.show();
	return a.exec();
}
