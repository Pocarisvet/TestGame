#pragma once

#include "Hunter.h"
#include "Unit.h"
#include <deque>

class GameApp : public Hunter::HunterApp
{
public:
	GameApp();

	virtual void OnUpdate() override;

	virtual void OnKeyPressed(Hunter::KeyPressedEvent& event) override;
	virtual void OnKeyReleased(Hunter::KeyReleasedEvent& event) override;

private:
	Unit mCar;
	std::deque<Unit> mRocks;
	Hunter::Sprite mBackground;
	Hunter::Sprite mEndNotice;

	enum class Action
	{
		LeftMove,
		RightMove,
		Forward
	} mCarAction;

	bool mGameEnd;
	long long mFrameNumber;

};