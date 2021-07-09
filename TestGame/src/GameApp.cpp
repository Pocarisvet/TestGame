#include "..\include\GameApp.h"

GameApp::GameApp() : mCar("assets/car.png", 5), mCarAction(Action::Forward)
{

}

void GameApp::OnUpdate()
{
	if (mCarAction == Action::LeftMove)
	{
		if (mCar.GetXCoord() >= mCar.Speed())
			mCar.UpdateXCoord(-mCar.Speed());
		else
			mCar.SetXCoord(0);
	}
	else if (mCarAction == Action::RightMove)
	{
		if (mCar.GetXCoord() + mCar.Speed() < GameApp::GetWindowWidth())
			mCar.UpdateXCoord(mCar.Speed());
		else
			mCar.SetXCoord(GameApp::GetWindowWidth() - mCar.GetWidth());
	}
	mCar.Draw();

}

void GameApp::OnKeyPressed(Hunter::KeyPressedEvent& event)
{
	if (event.GetKeyCode() == HUNTER_KEY_LEFT)
	{
		mCarAction = Action::LeftMove;
	}
	else if (event.GetKeyCode() == HUNTER_KEY_RIGHT)
	{
		mCarAction = Action::RightMove;
	}
}


