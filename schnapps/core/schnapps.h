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

public:

	SCHNApps(QObject* parent = nullptr) :
		QObject(parent)
	{}

	~SCHNApps() override
	{}

public slots:

	void load_plugin()
	{
		std::cout << "load plugin" << std::endl;
	}

	void add_map(const QString& name)
	{
		MapHandler* m = new MapHandler(name);
		map_list_.add(m);
	}

	/**
	 * @brief  get the file path where application has been launched
	 * @return the path
	 */
	const QString& get_app_path() { return app_path_; }

public:

	QString app_path_;
	MapHandlerListModel map_list_;
};

} // namespace schnapps

#endif // CORE_SCHNAPPS_H_
