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

#ifndef UTILS_VIEW_RENDERER_H_
#define UTILS_VIEW_RENDERER_H_

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>

namespace schnapps
{

class ViewRenderer : public QObject, protected QOpenGLFunctions
{
	Q_OBJECT

public:

	ViewRenderer();
	~ViewRenderer();

	void set_viewport_size(const QSize& size) { viewport_size_ = size; }

public slots:

	void paint();

private:

	QSize viewport_size_;
	QOpenGLShaderProgram* program_;
};

}

#endif // UTILS_VIEW_RENDERER_H_
