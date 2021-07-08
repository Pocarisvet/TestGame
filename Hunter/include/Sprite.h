#pragma once

#include "HunterCentral.h"
#include "pch.h"

namespace Hunter
{
	class HUNTER_API Sprite
	{
	public:
		Sprite(const std::string& spriteFile);
		bool Load(const std::string& spriteFile);
		int GetWidth() const;
		int GetHeight() const;
		const unsigned char* GetImagePointer() const;
		~Sprite();

		Sprite(const Sprite& other) = delete;
		Sprite(Sprite&& other) = delete;
		Sprite& operator=(const Sprite& other) = delete;
		Sprite& operator=(Sprite&& other) = delete;

	private:
		unsigned char* mImage{ nullptr };
		int mWidth{ 0 };
		int mHeight{ 0 };
		int mNumChannels{ 0 };
	};
}