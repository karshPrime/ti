
#include <stdio.h>

#include "transform.h"
#include "datastream.h"

void print_help();
void print_usage();

// all supported actions with their flags
const Flags Actions[] = {
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
const uint ActionsCount = sizeof(Actions) / sizeof(Actions[0]);

int main(int argc, char** argv) {
	// exit if not sufficient args are provided
	if (argc < 2) {
		fprintf(stderr, "Error: Insufficient arguments provided.\n");
		print_usage();
		return 1;
	}
	char* cmd = argv[1];

	// check if user was requesting help
	if (check_cmd(&cmd, "-h", "--help")) {
		print_help();
		return 0;
	}

	// find corresponding action for given command
	uint lActionIndex = ActionsCount;
	for (uint i = 0; i < ActionsCount; i++) {
		if (check_cmd(&cmd, Actions[i].STrigger, Actions[i].LTrigger)) {
			lActionIndex = i;
			break;
		}
	}

	// invalid command was used
	if (lActionIndex == ActionsCount) {
		fprintf(stderr, "Error: Invalid Argument: %s\n", cmd);
		return 1;
	}

	// get data
	Input data;
	if (argc == 2) {
		// get data from pipes if only 1 args
		data = piped_data();
	} else {
		// when enough args are provided
		data.Values = &argv[2];
		data.Size = argc - 2;
	}

	// perform requested action on all arguments
	for (uint i = 0; i < data.Size; i++) {
		Actions[lActionIndex].Action(&data.Values[i]);
	}

	return 0;
}

void print_help() {
	printf("help\n");
}

void print_usage() {
	printf("$ ti {OPTION} text\n");
	printf("$ <stdout> | ti {OPTION}\n");
	printf("\nOPTIONS:\n");
	printf("\n");
}

