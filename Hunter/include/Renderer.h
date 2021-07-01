#pragma once

#include "Sprite.h"
#include "RendererImplementation.h"

namespace Hunter
{
	class Renderer
	{
	public:
		static void Init();
		static void ShutDown();
		static void Draw(const Sprite& image, int x_pos, int y_pos, int width, int height);

	private:
		Renderer();

		inline static Renderer* instance{ nullptr };
		RendererImplementation* mDrawingEngine{ nullptr };
	};
}