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

#include <utils/view.h>

namespace schnapps
{

View::View() :
	renderer_(nullptr)
{
	connect(this, SIGNAL(windowChanged(QQuickWindow*)), this, SLOT(handle_window_changed(QQuickWindow*)));
}

View::~View()
{}

void View::handle_window_changed(QQuickWindow* win)
{
	if (win)
	{
		connect(win, SIGNAL(beforeSynchronizing()), this, SLOT(sync()), Qt::DirectConnection);
		connect(win, SIGNAL(sceneGraphInvalidated()), this, SLOT(cleanup()), Qt::DirectConnection);

		win->setClearBeforeRendering(false);
	}
}

void View::sync()
{
	if (!renderer_)
	{
		renderer_ = new ViewRenderer();
		connect(window(), SIGNAL(beforeRendering()), renderer_, SLOT(paint()), Qt::DirectConnection);
	}
	renderer_->set_viewport_size(window()->size() * window()->devicePixelRatio());
}

void View::cleanup()
{
	if (renderer_)
	{
		delete renderer_;
		renderer_ = nullptr;
	}
}

} // namespace schnapps
