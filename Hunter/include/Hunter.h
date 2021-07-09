#pragma once

#include <HunterCentral.h>
#include <HunterApp.h>
#include "Sprite.h"
#include "Renderer.h"
#include "HunterKeys.h"

#define START_GAME(classname) \
	int main() \
	{ \
		classname* gamePointer = new classname; \
		gamePointer->GetApplication()->RunGame(); \
		delete gamePointer; \
	}

