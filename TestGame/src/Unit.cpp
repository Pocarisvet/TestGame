#include "..\include\Unit.h"
#include "Hunter.h"

Unit::Unit(const std::string& spritePath, int newSpeed):mImage(spritePath), mSpeed(newSpeed)
{

}

void Unit::SetXCoord(int newX)
{
	mXcoord = newX;
}

void Unit::SetYCoord(int newY)
{
	mYcoord = newY;
}

int Unit::GetXCoord() const
{
	return mXcoord;
}

int Unit::GetYCoord() const
{
	return mYcoord;
}

int Unit::Speed() const
{
	return mSpeed;
}

void Unit::UpdateXCoord(int change)
{
	mXcoord += change;
}

void Unit::UpdateYCoord(int change)
{
	mYcoord += change;
}

int Unit::GetWidth() const
{
	return mImage.GetWidth();
}

int Unit::GetHeight() const
{
	return mImage.GetHeight();
}

void Unit::Draw() const
{
	Hunter::Renderer::Draw(mImage, mXcoord, mYcoord, mImage.GetWidth(), mImage.GetHeight());
}

bool Unit::OverlapsWith(const Unit& other) const
{
	if ((mXcoord <= other.mXcoord && other.mXcoord <= mXcoord + GetWidth()) ||
		(mXcoord <= other.mXcoord + other.GetWidth() && other.mXcoord + other.GetWidth() <= mXcoord + GetWidth()))
	{
		if ((mYcoord <= other.mYcoord && other.mYcoord <= mYcoord + GetHeight()) ||
			(mYcoord <= other.mYcoord + other.GetHeight() && other.mYcoord + other.GetHeight() <= mYcoord + GetHeight()))

			return true;
	}

	return false;
}
