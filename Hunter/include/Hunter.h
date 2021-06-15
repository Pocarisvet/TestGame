#pragma once

#include <HunterCentral.h>
#include <HunterApp.h>

#define START_GAME(classname) \
	int main() \
	{ \
		classname::Init(); \
		classname::GetApplication()->RunGame(); \
	}

