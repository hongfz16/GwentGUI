#ifndef GAMEUNITMODEL_H
#define GAMEUNITMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "gameunit.h"
#include "gameconstant.h"

class gameUnitModel : public QAbstractListModel
{
	Q_OBJECT
public:
	enum UnitRoles {
		IdRole = Qt::UserRole + 1,
		NameRole,
		FightRole,
		ProtectionRole,
		LockedRole
	};

	gameUnitModel(QObject *parent=0);

	void addUnit(const gameUnit &unit);

	int rowCount(const QModelIndex &parent=QModelIndex()) const;

	QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;

protected:
	QHash<int, QByteArray> roleNames() const;

private:
	QList<gameUnit> myRow;

};

#endif // GAMEUNITMODEL_H
