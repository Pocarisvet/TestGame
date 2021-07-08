#pragma once

#include "HunterCentral.h"
#include "Window.h"
#include "KeyboardEvents.h"

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
		virtual void SwapBuffers() override;
		virtual void PollForEvent() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> newCallBack) override;

	private:
		struct Callbacks
		{
			std::function<void(KeyPressedEvent&)> KeyPressedCallback;
		} mCallbacks;

		GLFWwindow* window;
	};
}