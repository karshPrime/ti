
/* commands.h
 * declare structures and functions for command processing
 */

#pragma once

#include <stdbool.h>

#include "transform.h"
#include "crypto.h"

typedef unsigned int uint;

typedef enum {
	Transform,
	Crypto
} Call;

typedef struct {
	Call Type;
	const char* STrigger;
	const char* LTrigger;
	union {
		void(*Transform)(char**);
		void(*Crypto)(char**, char**);
	} Command;
} Action;

typedef struct {
	char*  Value;
	bool   InHeap;
} Data;

// all supported actions with their flags
const Action Actions[] = {
	{ Transform, "-c",	"--case",		lower		},
	{ Transform, "-C",	"--CASE",		upper		},
	{ Transform, "-s",	"--sentence",	sentence	},
	{ Transform, "-w",	"--word",		word		},
	{ Transform, "-r",	"--rotate13",	rotate13	},
	{ Transform, "-f",	"--flip",		flip		},
	{ Transform, "-m",	"--mock",		mock		},
	{ Transform, "-i",	"--charindx",	charindx	},
	{ Transform, "-a",	"--ascii",		ascii		},
	{ Transform, "-A", "--ascii-bin",	ascii_bin	}
};
const uint ActionsCount = sizeof(Actions) / sizeof(Actions[0]);

// called command
void   check_help(char** aInput);
Action get_action(char** aInput);

// input data
Data   get_data(int* argc, char*** argv, Call* aType);
void   free_data(Data* lData);
char*  get_key(int* argc, char*** argv);


