#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QList>
#include <QDebug>
#include "gameunit.h"
#include "gameconstant.h"
#include "gameunitmodel.h"

class gameController : public QObject
{
	Q_OBJECT
	Q_PROPERTY(gameUnitModel myHandCard READ getMyHandCard WRITE addMyHandCard NOTIFY myHandCardChanged)
public:
	explicit gameController(QObject *parent = nullptr);

signals:
	void myHandCardChanged();
public slots:

#ifdef DEBUG
	void addMyHandCard()
	{
		qDebug()<<"add";
		myHandCard.addUnit(gameUnit(100011));
	}
#endif

	gameUnitModel *getMyHandCard()
	{
		return &myHandCard;
	}

private:
	gameUnitModel myHandCard;
	gameUnitModel myFront;
	gameUnitModel myMiddle;
	gameUnitModel myBack;
	gameUnitModel opHandCard;
	gameUnitModel opFront;
	gameUnitModel opMiddle;
	gameUnitModel opBack;
};

#endif // GAMECONTROLLER_H
