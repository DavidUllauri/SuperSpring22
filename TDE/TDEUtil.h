#pragma once

#ifdef TDE_LIB
	#define TDE_API __declspec(dllexport)
#else
	#define TDE_API __declspec(dllimport)
#endif
