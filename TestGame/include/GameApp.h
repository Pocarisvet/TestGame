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

private:
	Unit mCar;
	std::deque<Unit> mRocks;

	enum class Action
	{
		LeftMove,
		RightMove,
		Forward
	} mCarAction;

};