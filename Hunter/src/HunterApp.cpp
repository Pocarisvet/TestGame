#include <pch.h>
#include "HunterApp.h"
#include "WindowsWindow.h"
#include "Renderer.h"
#include "Sprite.h"

namespace Hunter
{
	void HunterApp::RunGame()
	{
		HLOG("Start the game");
		
		Renderer::Init();

		Sprite test1{ "../Hunter/assets/sprites/football.png" };
		Sprite test2{ "../Hunter/assets/sprites/earth.png" };

		while (true)
		{
			Renderer::Draw(test1, 100, 100, test1.GetWidth(), test1.GetHeight());
			Renderer::Draw(test2, 100, 100, test2.GetWidth(), test2.GetHeight());

			appWindow->SwapBufferes();
			appWindow->PollForEvent();
		}
	}

	HunterApp* HunterApp::GetApplication()
	{
		return instance;
	}

	void HunterApp::Init()
	{
		if (instance == nullptr)
			instance = new HunterApp;
	}

	HunterApp::HunterApp()
	{
		assert(instance == nullptr);

#ifdef _HUNTER_WINDOWS
		appWindow = new WindowsWindow;
#else
	#Windows_supported_only
#endif
		bool success{ appWindow->CreateWindow(800, 600) };
		assert(success);
	}

	HunterApp::~HunterApp()
	{
		appWindow->DeleteWindow();
	}

	int HunterApp::GetWindowWidth()
	{
		return instance->appWindow->GetWidth();
	}

	int HunterApp::GetWindowHeight()
	{
		return instance->appWindow->GetHeight();
	}
}
