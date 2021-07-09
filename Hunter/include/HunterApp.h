#pragma once

#include "pch.h"
#include "HunterCentral.h"
#include "Window.h"
#include "KeyboardEvents.h"

namespace Hunter
{
	class HUNTER_API HunterApp
	{
	public:
		virtual void RunGame();
		static HunterApp* GetApplication();
		virtual ~HunterApp();

		virtual void OnUpdate();

		static int GetWindowWidth();
		static int GetWindowHeight();

		virtual void OnKeyPressed(KeyPressedEvent& event);
		virtual void OnKeyReleased(KeyReleasedEvent& event);

	protected:
		HunterApp();

	private:
		inline static HunterApp* instance{ nullptr };

		Hunter::Window* appWindow{ nullptr };

		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::microseconds mFrameDuration{ 16 };
	};
}

