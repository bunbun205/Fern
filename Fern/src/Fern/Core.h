#pragma once

#ifdef FN_PLATFORM_WINDOWS
	#ifdef FN_BUILD_DLL
		#define FERN_API __declspec(dllexport)
	#else
		#define FERN_API __declspec(dllimport)
	#endif
#else
	#error Fern only supports Windows!!!
#endif

#ifdef FN_ENABLE_ASSERTS
	#define FN_ASSERT(x, ...) { if(!(x)) { FN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define FN_CORE_ASSERT(x, ...) { if(!(x)) { FN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FN_ASSERT(x, ...)
	#define FN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)