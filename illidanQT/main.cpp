#include "XLogin.h"
#include "XMainWindow.h"
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

	XMainWindow xMainWindow;
	XLogin xLogin;

	if (xLogin.exec() == QDialog::Accepted)
	{
		xMainWindow.show();
		return a.exec();
	}
	
	return 0;
}
