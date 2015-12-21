#include <QApplication>
#include <QSplashScreen>
#include <QFileInfo>

#include <core/schnapps.h>

// #include <PythonQt.h>
// #include <gui/PythonQtScriptingConsole.h>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	QSplashScreen* splash = new QSplashScreen(QPixmap(":splash/cgogn/splash.png"));
	splash->show();
	splash->showMessage("Welcome to SCHNApps", Qt::AlignBottom | Qt::AlignCenter);

//	// init PythonQt and Python itself
//	PythonQt::init();

//	QStringList classNames;
//	classNames.append("View");
//	classNames.append("Camera");
//	classNames.append("Plugin");
//	classNames.append("MapHandlerGen");
//	PythonQt::self()->registerQObjectClassNames(classNames);

//	// get a smart pointer to the __main__ module of the Python interpreter
//	PythonQtObjectPtr python_context = PythonQt::self()->getMainModule();

//	PythonQtScriptingConsole* python_console = new PythonQtScriptingConsole(NULL, python_context);

//	schnapps::SCHNApps schnapps(app.applicationDirPath(), python_context, *python_console);
	schnapps::SCHNApps schnapps(app.applicationDirPath());

//	schnapps.show();

//	python_context.addObject("schnapps", &schnapps);

//	if(argc > 1)
//	{
//		QString filename(argv[1]);
//		QFileInfo fi(filename);
//		if (fi.exists())
//			//python_context.evalFile(fi.filePath());
//			schnapps.loadPythonScriptFromFile(fi.filePath());
//	}

	splash->finish(&schnapps);
	delete splash;

	return app.exec();
}
