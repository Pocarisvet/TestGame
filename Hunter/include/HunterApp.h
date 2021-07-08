#pragma once

#include "HunterCentral.h"
#include "Window.h"
#include "KeyboardEvents.h"

namespace Hunter
{
	class HUNTER_API HunterApp
	{
		public:
			void RunGame();
			static HunterApp* GetApplication();
			static void Init();
			virtual ~HunterApp();

			static int GetWindowWidth();
			static int GetWindowHeight();

			void OnKeyPressed(KeyPressedEvent& event);

		private:
			HunterApp();

			inline static HunterApp* instance{ nullptr };

			Hunter::Window* appWindow{ nullptr };
	};
}

