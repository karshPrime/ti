
/* commands.h
 * declare structures and functions for command processing
 */

#pragma once

#include <stdbool.h>

typedef unsigned int uint;
typedef void (*Call)(char**);

typedef struct {
	const char* STrigger;
	const char* LTrigger;
	Call		Command;
} Action;

typedef struct {
	char*  Value;
	bool   InHeap;
} Data;

extern const Action Actions[];
extern const uint ActionCount;

// call command
void check_help(const char** CMD);
Call get_action(const char** CMD);

// input data
Data get_data(const int* argc, char*** argv);
void free_data(Data* lData);

