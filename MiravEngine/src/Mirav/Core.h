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


#ifdef MV_ENABLE_ASSERTS
#define MV_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define MV_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define MV_ASSERT(x, ...)
#define MV_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x) 