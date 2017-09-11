#include "gamecontroller.h"

gameController::gameController(QObject *parent) : QObject(parent)
{
#ifdef DEBUG
	myHandCard.addUnit(gameUnit(100011));
	//qDebug()<<"constract";
	connect(this,SIGNAL(addMyHandCardSignal()),this,SLOT(addMyHandCard()));
#endif
}
