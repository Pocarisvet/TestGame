#pragma once

#include "Hunter.h"

class Unit
{
public:
	Unit(const std::string& spritePath, int newSpeed);

	void SetXCoord(int newX);
	void SetYCoord(int newY);
	int GetXCoord() const;
	int GetYCoord() const;
	int Speed() const;
	void UpdateXCoord(int change);
	void UpdateYCoord(int change);
	int GetWidth() const;
	int GetHeight() const;

	void Draw() const;
	bool OverlapsWith(const Unit& other) const;

private:
	Hunter::Sprite mImage;
	int mXcoord;
	int mYcoord;
	int mSpeed;

};