#pragma once

#include "HunterCentral.h"
#include "Window.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Hunter
{
	class HUNTER_API WindowsWindow final : public Hunter::Window
	{
	public:
		virtual bool CreateWindow(unsigned int width, unsigned int height) override;
		virtual void DeleteWindow() override;
		virtual void SwapBufferes() override;
		virtual void PollForEvent() override;

	private:
		GLFWwindow* window;
	};
}