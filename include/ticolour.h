
#ifndef TICOLOUR_H
#define TICOLOUR_H

#ifdef _WIN32
	#ifdef BUILD_DLL
		#define DLL_EXPORT __declspec(dllexport)
	#else
		#define DLL_EXPORT __declspec(dllimport)
	#endif
#else
	#define DLL_EXPORT
#endif

DLL_EXPORT void dark_red(char** aText);
DLL_EXPORT void dark_blue(char** aText);
DLL_EXPORT void dark_green(char** aText);
DLL_EXPORT void light_red(char** aText);
DLL_EXPORT void light_blue(char** aText);
DLL_EXPORT void light_green(char** aText);

#endif // TICOLOUR_H
