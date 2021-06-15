#pragma once

#include <HunterCentral.h>

namespace Hunter
{
	class HUNTER_API HunterApp
	{
		public:
			void RunGame();
			static HunterApp* GetApplication();
			static void Init();
		private:
			HunterApp();
			inline static HunterApp* instance{ nullptr };
	};
}

