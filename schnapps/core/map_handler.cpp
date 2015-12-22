#include <core/map_handler.h>

namespace schnapps
{

QString MapHandler::name() const
{
	return name_;
}

unsigned int MapHandler::dimension() const
{
	return dimension_;
}


MapHandlerListModel::MapHandlerListModel(QObject* parent) :
	QAbstractListModel(parent)
{}

void MapHandlerListModel::add_map(const MapHandler& m)
{
	beginInsertRows(QModelIndex(), rowCount(), rowCount());
	map_handlers_.append(m);
	endInsertRows();
}

int MapHandlerListModel::rowCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return map_handlers_.count();
}

QVariant MapHandlerListModel::data(const QModelIndex& index, int role) const
{
	if (index.row() < 0 || index.row() >= map_handlers_.count())
		return QVariant();

	const MapHandler& mh = map_handlers_[index.row()];
	if (role == NameRole)
		return mh.name();
	else if (role == DimensionRole)
		return mh.dimension();
	return QVariant();
}

QHash<int, QByteArray> MapHandlerListModel::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[NameRole] = "name";
	roles[DimensionRole] = "dimension";
	return roles;
}

} // namespace schnapps
