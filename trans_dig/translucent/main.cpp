
/*
	Author: shiroki@www.cuteqt.com
	License: GPLv2
*/

#include <QApplication>
#include "mainwin.h"
#include <QWSServer>
int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QWSServer::setBackground(QColor(0,0,0,0));

	MainWin mw;
	mw.show();
	return app.exec();
}
