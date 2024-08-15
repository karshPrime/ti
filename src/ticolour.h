
#pragma once

#ifdef TICOLOR_EXPORTS
	#define TICOLOR_API __declspec(dllexport)
#else
	#define TICOLOR_API __declspec(dllimport)
#endif

TICOLOR_API void dark_red(char** aText);
TICOLOR_API void dark_blue(char** aText);
TICOLOR_API void dark_green(char** aText);

TICOLOR_API void light_red(char** aText);
TICOLOR_API void light_blue(char** aText);
TICOLOR_API void light_green(char** aText);
