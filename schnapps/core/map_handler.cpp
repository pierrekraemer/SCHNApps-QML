/*******************************************************************************
* SCHNApps                                                                     *
* Copyright (C) 2015, IGG Group, ICube, University of Strasbourg, France       *
*                                                                              *
* This library is free software; you can redistribute it and/or modify it      *
* under the terms of the GNU Lesser General Public License as published by the *
* Free Software Foundation; either version 2.1 of the License, or (at your     *
* option) any later version.                                                   *
*                                                                              *
* This library is distributed in the hope that it will be useful, but WITHOUT  *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License  *
* for more details.                                                            *
*                                                                              *
* You should have received a copy of the GNU Lesser General Public License     *
* along with this library; if not, write to the Free Software Foundation,      *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.           *
*                                                                              *
* Web site: http://cgogn.unistra.fr/                                           *
* Contact information: cgogn@unistra.fr                                        *
*                                                                              *
*******************************************************************************/

#include <schnapps/core/map_handler.h>

namespace schnapps
{

/*******************************************************************************
 * MapHandler class
 ******************************************************************************/

QString MapHandler::name() const
{
	return name_;
}

unsigned int MapHandler::dimension() const
{
	return dimension_;
}

/*******************************************************************************
 * MapHandlerListModel class
 ******************************************************************************/

MapHandlerListModel::MapHandlerListModel(QObject* parent) :
	QAbstractListModel(parent)
{}

void MapHandlerListModel::append(MapHandler* m)
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

	MapHandler* mh = map_handlers_[index.row()];
	if (role == NameRole)
		return mh->name();
	else if (role == DimensionRole)
		return mh->dimension();
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
