#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QVariant>

#include "gamecontroller.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	qmlRegisterType<gameController>("Gwent.GameController",1,0,"gameController");


	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/gamePlaying.qml")));

	//gameController gc;

	//QQmlContext *ctxt=engine.rootContext();
	//ctxt->setContextProperty("gc",&gc);
	//ctxt->setContextProperty("myHandCard",&(gc.myHandCard));


	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
