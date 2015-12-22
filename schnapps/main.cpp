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

#include <QApplication>
#include <QtQml>
#include <QtQml/QQmlApplicationEngine>

#include <core/schnapps.h>
#include <core/map_handler.h>
#include <utils/view.h>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	qmlRegisterType<schnapps::SCHNApps>("schnapps", 1, 0, "SCHNApps");
	qmlRegisterType<schnapps::View>("schnapps", 1, 0, "View");
	qmlRegisterType<schnapps::MapHandlerListModel>("schnapps", 1, 0, "MapHandlerListModel");

	QQmlApplicationEngine engine(QUrl("qrc:///ui/schnapps.qml"));

	return app.exec();
}
