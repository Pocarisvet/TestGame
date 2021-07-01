#pragma once

#include "Sprite.h"

namespace Hunter
{
	class RendererImplementation
	{
	public:
		virtual void Init() = 0;
		virtual void Draw(const Sprite& image, int x_pos, int y_pos, int width, int height) = 0;
		virtual ~RendererImplementation() = 0 {};
	};
}