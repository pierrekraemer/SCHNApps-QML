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
#include <iostream>

#include <QPluginLoader>
#include <QFileInfo>

#include <schnapps/core/plugin.h>

namespace schnapps
{

/*******************************************************************************
 * Plugin class
 ******************************************************************************/

Plugin::Plugin(const QString& file_name, SCHNApps* schnapps) :
	name_(file_name),
	file_name_(file_name),
	schnapps_(schnapps),
	object_(nullptr)
{
	QFileInfo file_info(file_name_);
	name_ = file_info.baseName();
}

Plugin::~Plugin()
{
	std::cout << "plugin destroyed : " << name_.toStdString() << std::endl;
}

QString Plugin::name() const
{
	return name_;
}

QString Plugin::file_name() const
{
	return file_name_;
}

bool Plugin::is_loaded() const
{
	return object_ != nullptr;
}

void Plugin::load()
{
	assert(!is_loaded());

	QPluginLoader loader(file_name_);
	QObject* plugin_object = loader.instance();
	if (plugin_object)
	{
		object_ = qobject_cast<PluginObject*>(plugin_object);
		if (!object_->enable())
		{
			delete object_;
			object_ = nullptr;
			std::cout << "Plugin enabling failed: " << name_.toStdString() << std::endl;
		}
		else
		{
			std::cout << "Plugin successfully loaded: " << name_.toStdString() << std::endl;
			object_->set_schnapps(schnapps_);
		}
	}
	else
		std::cout << "Plugin loading failed: " << name_.toStdString() << std::endl;
}

void Plugin::unload()
{
	assert(is_loaded());

	object_->disable();
	delete object_;
	object_ = nullptr;
	std::cout << "Plugin successfully unloaded: " << name_.toStdString() << std::endl;
}

void Plugin::invoke(const QString& function_name)
{
	assert(is_loaded());

	object_->invoke(function_name);
}

/*******************************************************************************
 * PluginObject class
 ******************************************************************************/

void PluginObject::set_schnapps(SCHNApps *s)
{
	schnapps_ = s;
}

/*******************************************************************************
 * PluginListModel class
 ******************************************************************************/

PluginListModel::PluginListModel(QObject* parent) :
	QAbstractListModel(parent)
{}

void PluginListModel::append(Plugin* m)
{
	beginInsertRows(QModelIndex(), rowCount(), rowCount());
	plugins_.append(m);
	endInsertRows();
}

int PluginListModel::rowCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return plugins_.count();
}

QVariant PluginListModel::data(const QModelIndex& index, int role) const
{
	if (index.row() < 0 || index.row() >= plugins_.count())
		return QVariant();

	Plugin* p = plugins_[index.row()];
	if (role == NameRole)
		return p->name();
	else if (role == LoadedRole)
		return p->is_loaded();
	return QVariant();
}

Plugin* PluginListModel::plugin(const QString& name)
{
	std::cout << "nb plugins : " << plugins_.count() << std::endl;
	foreach (Plugin* p, plugins_) {
		std::cout << "plugin @ : " << p << std::endl;
		std::cout << "plugin name : " << p->name().toStdString() << std::endl;
		if (p->name() == name)
			return p;
	}
	return nullptr;
}

QHash<int, QByteArray> PluginListModel::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[NameRole] = "name";
	roles[LoadedRole] = "loaded";
	return roles;
}

} // namespace schnapps
