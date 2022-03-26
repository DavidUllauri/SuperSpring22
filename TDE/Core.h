#pragma once

#include "pch.h"

#ifdef TDE_WINDOWS
	#ifdef TDE_LIB
		#define TDE_API __declspec(dllexport)
	#else
		#define TDE_API __declspec(dllimport)
	#endif
#else
	#define TDE_API
#endif

#ifdef TDE_DEBUG
	#define TDE_LOG(x) std::cout<<x<<std::endl;
#else
	#define TDE_LOG(x)
#endif