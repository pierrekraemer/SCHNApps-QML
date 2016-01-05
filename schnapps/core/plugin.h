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

#ifndef CORE_PLUGIN_H_
#define CORE_PLUGIN_H_

#include <QAbstractListModel>

namespace schnapps
{

class SCHNApps;
class PluginObject;


class Plugin : public QObject
{
	Q_OBJECT

public:

	Plugin(const QString& file_name, SCHNApps* schnapps);
	~Plugin();

	QString name() const;
	QString file_name() const;
	bool is_loaded() const;

public slots:

	void load();
	void unload();
	void invoke(const QString& function_name);

private slots:

private:

	QString name_;
	QString file_name_;
	SCHNApps* schnapps_;
	PluginObject* object_;
};


class PluginObject : public QObject
{
	Q_OBJECT

public:

	PluginObject() {}
	~PluginObject() {}

	virtual bool enable() = 0;
	virtual void disable() = 0;
	virtual void invoke(const QString& function_name) = 0;

	void set_schnapps(SCHNApps* s);

protected:

	SCHNApps* schnapps_;
};


class PluginListModel : public QAbstractListModel
{
	Q_OBJECT

public:

	enum PluginRoles
	{
		NameRole = Qt::UserRole + 1,
		LoadedRole
	};

	PluginListModel(QObject* parent = nullptr);

	void append(Plugin* p);

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

	Plugin* plugin(const QString& name);

protected:

	QHash<int, QByteArray> roleNames() const;

private:

	QList<Plugin*> plugin_list_;
};

} // namespace schnapps

Q_DECLARE_INTERFACE(schnapps::PluginObject, "icube.igg.schnapps.PluginObject")

#endif // CORE_PLUGIN_H_
