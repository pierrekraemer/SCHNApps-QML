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

#include <cassert>

#include <QFileDialog>

#include <schnapps/core/schnapps.h>

namespace schnapps
{

SCHNApps::SCHNApps(QObject* parent) :
	QObject(parent)
{}

SCHNApps::~SCHNApps()
{}

const QString& SCHNApps::app_path() const
{
	return app_path_;
}

PluginListModel* SCHNApps::plugin_list()
{
	return &plugin_list_;
}

MapHandlerListModel* SCHNApps::map_list()
{
	return &map_list_;
}

void SCHNApps::print_status() const
{
	std::cout << "nb maps : " << map_list_.rowCount() << std::endl;
}

Plugin* SCHNApps::plugin(const QString& name)
{
	return plugin_list_.plugin(name);
}

void SCHNApps::add_plugin()
{
	QString file_name = QFileDialog::getOpenFileName(nullptr, "Add plugin", app_path_, "Plugin files (*.so *.dylib)");
	QFileInfo fi(file_name);
	if(fi.exists())
	{
		Plugin* p = new Plugin(file_name, this);
		add_plugin(p);
	}
}

void SCHNApps::add_plugin(Plugin* p)
{
	assert(p != nullptr);
	plugin_list_.append(p);
}

void SCHNApps::add_map(MapHandler* map)
{
	assert(map != nullptr);
	map_list_.append(map);
}

} // namespace schnapps
