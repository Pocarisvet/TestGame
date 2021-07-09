#include <pch.h>
#include "HunterApp.h"
#include "WindowsWindow.h"
#include "Renderer.h"
#include "Sprite.h"
#include "HunterKeys.h"

namespace Hunter
{
	void HunterApp::RunGame()
	{
		HLOG("Start the game");
		
		Renderer::Init();

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true)
		{
			Renderer::ClearFrame();

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			appWindow->SwapBuffers();
			appWindow->PollForEvent();

			mNextFrameTime += mFrameDuration;
		}
	}

	HunterApp* HunterApp::GetApplication()
	{
		return instance;
	}

	HunterApp::HunterApp()
	{
		assert(instance == nullptr);

		instance = this;

#ifdef _HUNTER_WINDOWS
		appWindow = new WindowsWindow;
#else
	#Windows_supported_only
#endif

		bool success{ appWindow->CreateWindow(800, 800) };
		assert(success);

		appWindow->SetKeyPressedCallback([this](KeyPressedEvent& event) {OnKeyPressed(event); });
		appWindow->SetKeyReleasedCallback([this](KeyReleasedEvent& event) {OnKeyReleased(event); });
	}

	HunterApp::~HunterApp()
	{
		appWindow->DeleteWindow();
	}

	void HunterApp::OnUpdate()
	{

	}

	int HunterApp::GetWindowWidth()
	{
		return instance->appWindow->GetWidth();
	}

	int HunterApp::GetWindowHeight()
	{
		return instance->appWindow->GetHeight();
	}

	void HunterApp::OnKeyPressed(KeyPressedEvent& event)
	{

	}

	void HunterApp::OnKeyReleased(KeyReleasedEvent& event)
	{

	}
}
