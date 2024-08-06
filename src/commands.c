
/* commands.c
 * code to parse user flags and input and return understanding
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "printbreak.h"


//- Local Helper ---------------------------------------------------------------

// check if input is same as any existing commands
bool check_cmd(char** aInput, const char* aShort, const char* aLong) {
	return !( strcmp(*aInput, aShort) && strcmp(*aInput, aLong) );
}

// get data from pipes
char* get_piped_data() {
	char *inputBuffer = NULL;
	size_t bufferSize = 0;
	size_t inputSize = 0;
	int ch;

	while ((ch = getchar()) != EOF) {
		if (inputSize >= bufferSize) {
			bufferSize += 256;
			char* newBuffer = realloc(inputBuffer, bufferSize);
			error_mem_alloc(&newBuffer);
			inputBuffer = newBuffer;
		}
		inputBuffer[inputSize++] = (char)ch;
	}

	if (inputSize >= bufferSize) {
		bufferSize += 1;
		char* newBuffer = realloc(inputBuffer, bufferSize);
		error_mem_alloc(&newBuffer);
		inputBuffer = newBuffer;
	}
	inputBuffer[inputSize] = '\0';
	return inputBuffer;
}


//- Export Functions -----------------------------------------------------------

// if user requested help, print help menu and exit
void check_help(char** aInput) {
	if (check_cmd(aInput, "-h", "--help"))
		print_help();
}

// return Action if triggered command was valid, else terminate
Action get_action(char** aInput) {
	Action Result;

	return Result;
}

// check for data in args and pipe and return it
Data get_data(int* argc, char*** argv, Call* aType) {
	Data Result;

	return Result;
}

// if data is stored in heap, free it
void free_data(Data* lData) {
	if (lData->InHeap)
		free(lData->Value);
}

// scrape inputs and return key for cryptograpy
char* get_key(int* argc, char*** argv) {
	char* Result;

	return Result;
}

