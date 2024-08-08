
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

// called command
void check_help(char** aInput);
uint get_action_id(char** aInput);

// input data
Data get_data(const int* argc, char*** argv);
void free_data(Data* lData);

