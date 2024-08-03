
/* datastream.h
 * declare structures and functions for data processing and storage
 */

#pragma once

#include <stdbool.h>

typedef unsigned int uint;

typedef struct {
	char*	STrigger;
	char*	LTrigger;
	void	(*Action)(char**);
} Flags;

typedef struct {
	char**	Values;
	uint	Size;
} Input;

Input piped_data();
bool check_cmd(char** aInput, char* aShort, char* aLong);

