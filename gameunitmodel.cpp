#include "gameunitmodel.h"

gameUnitModel::gameUnitModel(QObject *parent) : QAbstractListModel(parent)
{
}

void gameUnitModel::addUnit(const gameUnit &unit)
{
	beginInsertRows(QModelIndex(),rowCount(),rowCount());
	myRow<<unit;
	endInsertRows();
}

int gameUnitModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return myRow.count();
}

QVariant gameUnitModel::data(const QModelIndex &index, int role) const
{
	if(index.row()<0 || index.row()>=myRow.count())
		return QVariant();

	const gameUnit &unit=myRow[index.row()];
	if(role == IdRole)
		return unit.__id();
	else if(role == NameRole)
		return unit.__name();
	else if(role == FightRole)
		return unit.__fight();
	else if(role == ProtectionRole)
		return unit.__protection();
	else if(role == LockedRole)
		return unit.__locked();

	return QVariant();
}
QHash<int, QByteArray> gameUnitModel::roleNames() const {
	QHash<int, QByteArray> roles;
	roles[IdRole] = "id";
	roles[NameRole] = "name";
	roles[FightRole] = "fight";
	roles[ProtectionRole] = "protection";
	roles[LockedRole] = "locked";
	return roles;
}
