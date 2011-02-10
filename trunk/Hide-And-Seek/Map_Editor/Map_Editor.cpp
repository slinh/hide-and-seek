#include <QtGui/QApplication>
#include <QtGui/QPushButton>
#include "MainWindow.h"
#include <iostream>

// 34Lettres functions
#include <Alloc.h>
#include <LoggerTypes.h>
#include <engineTypes.h>

using namespace psp::MapEditor;

int main(int argc, char *argv[])
{
#ifdef DEBUG
	// Init functions rustines
	INITDOMAINMEMORYMANAGER
	LOGINSTANCE(TLoggerFile)
	//LOGC("test");
#endif

	QApplication app(argc, argv);

	MainWindow* fenetre = NEW_IN_DOMAIN(Tools) MainWindow();

    fenetre->show();

	int result = app.exec();

	DELETE_IN_DOMAIN(Tools) fenetre;

#ifdef DEBUG
	// End functions rustines
	REPORTLEAKS
	LOGCLOSE
#endif

    return result;
}