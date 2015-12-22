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

#ifndef CORE_SCHNAPPS_H_
#define CORE_SCHNAPPS_H_

#include <iostream>
#include <QObject>

#include <core/map_handler.h>

namespace schnapps
{

class SCHNApps : public QObject
{
	Q_OBJECT
	Q_PROPERTY(MapHandlerListModel* map_list READ map_list NOTIFY map_list_changed)

public:

	SCHNApps(QObject* parent = nullptr) :
		QObject(parent)
	{
		map_list_.add_map(MapHandler("Bunny"));
		map_list_.add_map(MapHandler("Raptor"));
	}

	~SCHNApps() override
	{}

	const QString& app_path() { return app_path_; }

	MapHandlerListModel* map_list() { return &map_list_; }

public slots:

	void print_status()
	{
		std::cout << "nb maps : " << map_list_.rowCount() << std::endl;
	}

	void add_map(const QString& name)
	{
		map_list_.add_map(MapHandler(name));
	}

signals:

	void map_list_changed();

private:

	QString app_path_;
	MapHandlerListModel map_list_;
};

} // namespace schnapps

#endif // CORE_SCHNAPPS_H_
