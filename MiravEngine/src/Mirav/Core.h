#pragma once

#ifdef MV_PLATFORM_WINDOWS
	#ifdef MV_BUILD_DLL
		#define Mirav_API __declspec(dllexport)
	#else
		#define Mirav_API __declspec(dllimport)
	#endif
#else
	#error the mirav engine only supports Windows!
#endif