
/* printbreak.c
 * print information (success or failure) and exit
 */

#include <stdio.h>
#include <stdlib.h>

#include "printbreak.h"


//- Local Helper ---------------------------------------------------------------

// format usage options
void print_option(char* s, char* l, char* d) {
	printf("  %-3s %-11s %s\n", s, l, d);
}

// print command usage
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


//- Export Functions -----------------------------------------------------------

// break if invalid command
void error_invalid_command(const char** aArgument) {
	fprintf(stderr, "Error: Invalid Argument: %s\n", *aArgument);
	print_usage();
	exit(1);
} 

// break if not enough arguments
void error_missing_args(int* argc) {
	if (*argc < 2) {
		fprintf(stderr, "Error: Insufficient arguments provided.\n");
		print_usage();
		exit(1);
	}
}

void error_mem_alloc(char** aBuffer) {
	if (!aBuffer) {
		fprintf(stderr, "Error: Memory allocation\n");
		free(aBuffer);
		exit(1);
	}
}

// break after printing help
void print_help() {
	printf("Text Invert (ti): Utility to invert text in differet forms.\n");

	print_usage();

	printf("INTERACTIVE MODE:\n");
	printf("  When the utility is invoked with only an OPTION and no text, it enters\n");
	printf("  interactive mode. In this mode, text can be entered at the prompt. To exit\n");
	printf("  interactive mode and trigger the action, press `Ctrl+D`.\n");

	exit(0);
}

