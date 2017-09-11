#ifndef GAMEUNIT_H
#define GAMEUNIT_H

#include <QObject>
#include <QString>

#include "cardmanager.h"
#include "gameconstant.h"

class gameUnit //: public QObject
{
	//Q_OBJECT
/*
	Q_PROPERTY(int fight READ __fight WRITE setFight)
	Q_PROPERTY(int protection READ __protection WRITE setProtection)
	Q_PROPERTY(bool locked READ __locked WRITE setLock)
	Q_PROPERTY(int id READ __id)
	Q_PROPERTY(QString name READ __name)
*/
public:
	explicit gameUnit(int _id);//, QObject *parent = nullptr);

private:
	int id;
	QString name;
	int fight;
	int protection;
	bool locked;
	QString imgFile;

public:
	int __id() const;
	QString __name() const;
	int __fight() const;
	int __protection() const;
	bool __locked() const;

	void setFight(int _fight);
	void setProtection(int _protection);
	void setLock(bool _lock);
signals:

public slots:
};

#endif // GAMEUNIT_H
