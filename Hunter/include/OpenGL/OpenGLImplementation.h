#pragma once

#include "RendererImplementation.h"
#include "OpenGL/OpenGLShdr.h"

namespace Hunter
{
	class OpenGLImplementation : public RendererImplementation
	{
	public:
		OpenGLImplementation();
		virtual void Init() override;
		virtual void Draw(const Sprite& image, int x_pos, int y_pos, int width, int height) override;
		virtual void ClearFrame() override;
		virtual ~OpenGLImplementation();

	private:
		OpenGLShdr mShaderDefault;
	};
}