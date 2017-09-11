#include "gameunit.h"

gameUnit::gameUnit(int _id):id(_id)//, QObject *parent) : QObject(parent), id(_id)
{
	CardManager cm(_id);
	fight=cm.getFight();
	protection=0;
	locked=false;
	name=cm.getName();
	imgFile=cm.getImgFile();
}

int gameUnit::__id() const
{
	return id;
}

QString gameUnit::__name() const
{
	return name;
}

int gameUnit::__fight() const
{
	return fight;
}

int gameUnit::__protection() const
{
	return protection;
}

bool gameUnit::__locked() const
{
	return locked;
}

void gameUnit::setFight(int _fight)
{
	fight=_fight;
}

void gameUnit::setProtection(int _protection)
{
	protection=_protection;
}

void gameUnit::setLock(bool _lock)
{
	locked=_lock;
}
