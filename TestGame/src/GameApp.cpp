#include "..\include\GameApp.h"

GameApp::GameApp() : mCar("assets/car.png", 10),
					 mBackground("assets/road.png"),
					 mEndNotice("assets/gameover.png"),
					 mCarAction(Action::Forward), 
					 mFrameNumber(0), 
					 mGameEnd(false)
{

}

void GameApp::OnUpdate()
{
	Hunter::Renderer::Draw(mBackground, 0, 0, mBackground.GetWidth(), mBackground.GetHeight());

	if (mGameEnd)
	{
		Hunter::Renderer::Draw(mEndNotice, 270, 350, mEndNotice.GetWidth(), mEndNotice.GetHeight());
		return;
	}

	if (mFrameNumber % 15 == 0)
	{
		std::string rockType{ "assets/rock" + std::to_string(rand() % 3 + 1) + ".png" };
		mRocks.emplace_back(rockType, 10);
		mRocks.back().SetYCoord(GameApp::GetWindowHeight());
		mRocks.back().SetXCoord(rand()%(GameApp::GetWindowWidth()-mRocks.back().GetWidth()));
	}

	if (mCarAction == Action::LeftMove)
	{
		if (mCar.GetXCoord() >= mCar.Speed())
			mCar.UpdateXCoord(-mCar.Speed());
		else
			mCar.SetXCoord(0);
	}
	else if (mCarAction == Action::RightMove)
	{
		if (mCar.GetXCoord() + mCar.GetWidth() + mCar.Speed() < GameApp::GetWindowWidth())
			mCar.UpdateXCoord(mCar.Speed());
		else
			mCar.SetXCoord(GameApp::GetWindowWidth() - mCar.GetWidth());
	}

	while (!mRocks.empty() && mRocks.front().GetYCoord() <= -mRocks.front().GetHeight())
		mRocks.pop_front();

	for (auto& rock : mRocks)
	{
		rock.UpdateYCoord(-rock.Speed());
		if (rock.OverlapsWith(mCar))
			mGameEnd = true;
	}

	for (const auto& rock : mRocks)
		rock.Draw();

	mCar.Draw();

	mFrameNumber++;
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

void GameApp::OnKeyReleased(Hunter::KeyReleasedEvent& event)
{
	if (event.GetKeyCode() == HUNTER_KEY_LEFT || event.GetKeyCode() == HUNTER_KEY_RIGHT)
		mCarAction = Action::Forward;
}


