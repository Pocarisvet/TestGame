#pragma once

#include "HunterCentral.h"

namespace Hunter
{
	class HUNTER_API Window 
	{
	public:
		virtual bool CreateWindow(unsigned int width, unsigned int height) = 0;
		virtual void DeleteWindow() = 0;
		virtual void SwapBufferes() = 0;
		virtual void PollForEvent() = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
	};
}