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