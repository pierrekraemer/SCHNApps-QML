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
#include <QQmlEngine>
#include <QQmlContext>
#include <QStandardItemModel>

#include <schnapps/core/plugin.h>
#include <schnapps/core/map_handler.h>

namespace schnapps
{

class SCHNApps : public QObject
{
	Q_OBJECT
	Q_PROPERTY(MapHandlerListModel* map_list READ map_list_model NOTIFY map_list_changed)
	Q_PROPERTY(PluginListModel* plugin_list READ plugin_list_model NOTIFY plugin_list_changed)

public:

	SCHNApps(QQmlContext* qml_context, QObject* parent = nullptr);
	~SCHNApps() override;

	const QString& app_path() const;

	MapHandlerListModel* map_list_model();
	PluginListModel* plugin_list_model();

public slots:

	void print_status() const;

	Plugin* plugin(const QString& name);
	void add_plugin();
	void add_plugin(Plugin* p);

	void add_map(MapHandler* map);

signals:

	void map_list_changed();
	void plugin_list_changed();

private:

	QString app_path_;
	QQmlContext* qml_context_;

	PluginListModel plugin_list_model_;
	MapHandlerListModel map_list_model_;
};

} // namespace schnapps

#endif // CORE_SCHNAPPS_H_
