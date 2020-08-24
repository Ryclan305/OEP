#pragma once

#ifdef OEP_PLATFORM_WINDOWS
	#ifdef OEP_BUILD_DLL
		#define OEP_API __declspec(dllexport)
	#else
		#define OEP_API __declspec(dllimport)
	#endif
#else 
	#error OEP only supports Windows!
#endif

#ifdef OEP_ENABLE_ASSERTS
	#define OEP_ASSERT(x, ...) { if(!(x)) { OEP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define OEP_CORE_ASSERT(x, ...) { if(!(x)) { OEP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define OEP_ASSERT(x, ...)
	#define OEP_CORE_ASSERT(x, ...)
#endif

#define BT(x) (1 << x)

#define OEP_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)