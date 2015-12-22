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
		name_(name),
		dimension_(2)
	{}

	QString name() const;
	unsigned int dimension() const;

private:

	QString name_;
	unsigned int dimension_;
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

	MapHandlerListModel(QObject* parent = nullptr);

	void add_map(const MapHandler& m);

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

protected:

	QHash<int, QByteArray> roleNames() const;

private:

	QList<MapHandler> map_handlers_;
};

} // namespace schnapps

#endif // CORE_MAP_HANDLER_H_
