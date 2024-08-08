
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
bool check_cmd(const char** aInput, const char* aShort, const char* aLong) {
	return !(strcmp(*aInput, aShort) && strcmp(*aInput, aLong));
}

// get data from pipes
char* get_piped_data() {
	char *Result = NULL; // input buffer
	size_t lBufferSize = 0;
	size_t lInputSize = 0;
	int lSingleChar;

	while ((lSingleChar = getchar()) != EOF) {
		if (lInputSize >= lBufferSize) {
			lBufferSize += 256;
			char* newBuffer = realloc(Result, lBufferSize);
			error_mem_alloc(&newBuffer);
			Result = newBuffer;
		}
		Result[lInputSize++] = (char)lSingleChar;
	}

	if (lInputSize >= lBufferSize) {
		lBufferSize += 1;
		char* newBuffer = realloc(Result, lBufferSize);
		error_mem_alloc(&newBuffer);
		Result = newBuffer;
	}
	Result[lInputSize] = '\0';

	return Result;
}

//- Export Functions -----------------------------------------------------------

// if user requested help, print help menu and exit
void check_help(const char** CMD) {
	if (check_cmd(CMD, "-h", "--help")) {
		print_help();
	}
}

// return Action if triggered command was valid, else terminate
Call get_action(const char** CMD) {
	for (uint i = 0; i < ActionCount; i++) {
		if (check_cmd(CMD, Actions[i].STrigger, Actions[i].LTrigger)) {

			return Actions[i].Command;
		}
	}

	// exit the program informing user about invalid command use
	error_invalid_command(CMD);

	// this will never be reached due to the above exit call
	static Call Result;
	return Result;
}

// check for data in args and pipe and return it
Data get_data(const int* argc, char*** argv) {
	Data Result;
	const uint cArgsCountShouldBe = 2;

	if (*argc == cArgsCountShouldBe) {
		Result.Value = get_piped_data();
		Result.InHeap = true;
	} else {
		Result.Value = (*argv)[cArgsCountShouldBe];
		Result.InHeap = false;
	}

	return Result;
}

// if data is stored in heap, free it
void free_data(Data* lData) {
	if (lData->InHeap) {
		free(lData->Value);
	}
}

