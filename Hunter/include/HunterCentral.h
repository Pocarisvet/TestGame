#pragma once

#ifdef _HUNTER_DLL_BUILD
	#define HUNTER_API __declspec(dllexport)
#else
	#define HUNTER_API __declspec(dllimport)
#endif

#ifdef _MYDEBUG
	#define HLOG(x) std::cout << x << std::endl;
#else
	#define HLOG(x) 
#endif

