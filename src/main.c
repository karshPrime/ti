
#include <stdio.h>
#include <stdlib.h>

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
	{ "-a",	"--ascii",		ascii	 },
	{ "-A", "--ascii-bin",	ascii_bin}
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
		print_usage();
		return 1;
	}

	// get data
	char* data;
	if (argc > 2) {
		// when enough args are provided
		data = argv[2];
	} else {
		// get data from pipes
		data = piped_data();
	}

	// perform requested action
	Actions[lActionIndex].Action(&data);

	// free data if only it was derived from pipes
	if (argc == 2)
		free(data);

	return 0;
}

void print_help() {
	printf("Text Invert (ti): Utility to invert text in differet forms.\n");
	print_usage();

	printf("INTERACTIVE MODE:\n");
	printf("  When the utility is invoked with only an OPTION and no text, it enters\n");
	printf("  interactive mode. In this mode, text can be entered at the prompt. To exit\n");
	printf("  interactive mode and trigger the action, press `Ctrl+D`.\n");
}

void print_option(char* s, char* l, char* d) {
	printf("  %-3s %-11s %s\n", s, l, d);
}

void print_usage() {
	printf("\nUSAGE:\n");
	printf("  $ ti {OPTION} text\n");
	printf("  $ <stdout> | ti {OPTION}\n");
	printf("\nOPTIONS:\n");
	print_option("c", "case", "lowercase all text");
	print_option("C", "CASE", "upperCase all text");
	print_option("s", "sentence", "Sentence case all text");
	print_option("w", "word", "Capitalise All Words");
	print_option("r", "rotate13", "hfr ebgngvba 13 nytbevguz");
	print_option("f", "flip", "fLIP CASES");
	print_option("m", "mock", "mOcK TeXt");
	print_option("i", "index", "individual letter's alphabetic index");
	print_option("a", "ascii", "individual letter's ASCII decimal");
	print_option("A", "ascii-bin", "individual letter's ASCII binary");
	printf("\n");
}

