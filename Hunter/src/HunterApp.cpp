#include <pch.h>
#include "HunterApp.h"
#include "WindowsWindow.h"

namespace Hunter
{
	void HunterApp::RunGame()
	{
		HLOG("Starting the game")

		while (true)
		{
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
}
