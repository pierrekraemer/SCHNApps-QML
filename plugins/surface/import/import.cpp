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

#include <QFileDialog>
#include <QFileInfo>

#include <plugins/surface/import/import.h>

namespace schnapps
{

bool SurfaceImportPlugin::enable()
{
	return true;
}

void SurfaceImportPlugin::disable()
{

}

void SurfaceImportPlugin::invoke(const QString& function_name)
{
	if (function_name == "import_mesh")
		return import_mesh();
	std::cout << "Function does not exist" << std::endl;
}

void SurfaceImportPlugin::import_mesh()
{
	QString file_name = QFileDialog::getOpenFileName(nullptr, "Import mesh", this->schnapps_->app_path(), "Surface mesh files (*.off *.obj)");
	import_mesh(file_name);
}

void SurfaceImportPlugin::import_mesh(const QString& file_name)
{
	QFileInfo fi(file_name);
	if(fi.exists())
	{
		cgogn::CMap2* map = new cgogn::CMap2();
		map->import(file_name.toStdString());
		MapHandler* mh = new MapHandler(file_name, map);
		this->schnapps_->add_map(mh);
	}
}

} // namespace schnapps
