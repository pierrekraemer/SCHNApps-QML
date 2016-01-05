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

#include <schnapps/utils/view_renderer.h>
#include <iostream>

namespace schnapps
{

ViewRenderer::ViewRenderer() :
	program_(nullptr)
{}

ViewRenderer::~ViewRenderer()
{
	delete program_;
}

void ViewRenderer::paint()
{
	if (!program_)
	{
		initializeOpenGLFunctions();

		std::cout << glGetString(GL_VERSION) << std::endl;

		program_ = new QOpenGLShaderProgram();

		program_->addShaderFromSourceCode(QOpenGLShader::Vertex,
			"attribute highp vec4 vertices;"
			"varying highp vec2 coords;"
			"void main() {"
			"    gl_Position = vertices;"
			"    coords = vertices.xy;"
			"}"
		);

		program_->addShaderFromSourceCode(QOpenGLShader::Fragment,
			"varying highp vec2 coords;"
			"void main() {"
			"    lowp float i = 1. - (pow(abs(coords.x), 4.) + pow(abs(coords.y), 4.));"
			"    i = floor(i * 20.) / 20.;"
			"    gl_FragColor = vec4(coords * .5 + .5, i, i);"
			"}"
		);

		program_->bindAttributeLocation("vertices", 0);
		program_->link();
	}

	program_->bind();
	program_->enableAttributeArray(0);

	float values[] = {
		-1, -1,
		1, -1,
		-1, 1,
		1, 1
	};
	program_->setAttributeArray(0, GL_FLOAT, values, 2);

	glViewport(0, 0, viewport_size_.width(), viewport_size_.height());

	glDisable(GL_DEPTH_TEST);

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	program_->disableAttributeArray(0);
	program_->release();
}

} // namespace schnapps
