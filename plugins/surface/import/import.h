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

#ifndef PLUGIN_SURFACE_IMPORT_H_
#define PLUGIN_SURFACE_IMPORT_H_

#include <schnapps/core/schnapps.h>
#include <schnapps/core/plugin.h>
#include <schnapps/core/map_handler.h>

namespace schnapps
{

class SurfaceImportPlugin : public PluginObject
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "icube.igg.schnapps.PluginObject")
	Q_INTERFACES(schnapps::PluginObject)

public:

	bool enable() override;
	void disable() override;
	void invoke(const QString& function_name) override;

public slots:

	void import_mesh();
	void import_mesh(const QString& file_name);
};

} // namespace schnapps

#endif // PLUGIN_SURFACE_IMPORT_H_
