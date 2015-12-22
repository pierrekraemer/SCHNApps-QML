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

#ifndef CORE_MAP_HANDLER_H_
#define CORE_MAP_HANDLER_H_

#include <QAbstractListModel>

namespace schnapps
{

class MapHandler
{
public:

	MapHandler(const QString& name) :
		name_(name)
	{}

	QString name_;
};


class MapHandlerListModel : public QAbstractListModel
{
	Q_OBJECT

public:

	enum MapHandlerRoles
	{
		NameRole = Qt::UserRole + 1,
		DimensionRole
	};

	MapHandlerListModel(QObject* parent = nullptr)
	{}

	void add(MapHandler* m)
	{
		map_handlers_.append(m);
	}

	virtual int rowCount(const QModelIndex&) const { return map_handlers_.size(); }
	virtual QVariant data(const QModelIndex& index, int role) const
	{
		if(!index.isValid()) {
			return QVariant();
		}
		if(role == NameRole) {
			return QVariant(map_handlers_[index.row()]->name_);
		}
		return QVariant();
	}

	QHash<int, QByteArray> roleNames() const
	{
		QHash<int, QByteArray> roles;
		roles[NameRole] = "name";
		roles[DimensionRole] = "dimension";
		return roles;
	}

private:

	QVector<MapHandler*> map_handlers_;
};

} // namespace schnapps

#endif // CORE_MAP_HANDLER_H_
