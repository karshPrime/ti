
#include <stdio.h>
#include <string.h>
#include "transform.h"

void print_help();
void print_about();

typedef unsigned int uint;

struct Flags {
	char*	SCall;
	char*	LCall;
	void	(*Action)(char**);
};

int main(int argc, char** argv) {
	// exit if not sufficient args are provided
	if (argc < 2) {
		fprintf(stderr, "Error: Insufficient arguments provided.\n");
		print_help();
		return 1;
	}
	char* lCmd = argv[1];

	// all supported actions with their flags
	const struct Flags lActions[] = {
 		{ "-c",	"--case",		lower	 },
		{ "-C",	"--CASE",		upper	 },
		{ "-s",	"--sentence",	sentence },
		{ "-w",	"--word",		word	 },
		{ "-r",	"--rotate13",	rotate13 },
		{ "-f",	"--flip",		flip	 },
		{ "-m",	"--mock",		mock	 },
		{ "-i",	"--charindx",	charindx },
		{ "-a",	"--ascii",		ascii	 }
	};
	const uint lActionsCount = 9;

	// placeholder
	// give real values
	char** lArgs = argv;
	uint lArgsCount = argc;

	// find corresponding action for given command
	uint lActionIndex = lActionsCount;
	for (uint i = 0; i < lActionsCount; i++) {
		if (!strcmp(lCmd, lActions[i].SCall) ||
				!strcmp(lCmd, lActions[i].LCall)) 
		{
			lActionIndex = i;
			break;
		}
	}

	// invalid command was used
	if (lActionIndex == lActionsCount) {
		fprintf(stderr, "Invalid Argument: %s", lCmd);
		return 1;
	}

	// perform requested action on all arguments
	for (uint i = 1; i < lArgsCount; i++) {
		lActions[lActionIndex].Action(&lArgs[i]);
	}

	return 0;
}

void print_help() {
	printf("help\n");
}

void print_about() {
	printf("about\n");
}

