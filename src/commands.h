
/* commands.h
 * declare structures and functions for command processing
 */

#pragma once

#include <stdbool.h>

typedef unsigned int uint;

typedef enum {
	Transform,
	Crypto
} Call;

typedef struct {
	const char* STrigger;
	const char* LTrigger;
	union {
		void(*Transform)(char**);
		void(*Crypto)(char**, char**);
	} Command;
	const Call  Type;
} Action;

typedef struct {
	char*  Value;
	bool   InHeap;
} Data;

extern const Action Actions[];
extern const uint ActionsCount;

// called command
void   check_help(char** aInput);
Action get_action(char** aInput);

// input data
Data   get_data(int* argc, char*** argv, Call* aType);
void   free_data(Data* lData);
char*  get_key(int* argc, char*** argv);


