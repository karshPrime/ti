
/* datastream.c
 * code for parsing input data
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "datastream.h"

bool check_cmd(char** aInput, char* aShort, char* aLong) {
	return !( strcmp(*aInput, aShort) && strcmp(*aInput, aLong) );
}

char* piped_data() {
	char *inputBuffer = NULL;
	size_t bufferSize = 0;
	size_t inputSize = 0;
	int ch;

	while ((ch = getchar()) != EOF) {
		if (inputSize >= bufferSize) {
			bufferSize += 256;
			char *newBuffer = realloc(inputBuffer, bufferSize);
			if (!newBuffer) {
				fprintf(stderr, "Error: Memory allocation\n");
				free(inputBuffer);
				exit(1);
			}
			inputBuffer = newBuffer;
		}
		inputBuffer[inputSize++] = (char)ch;
	}

	if (inputSize >= bufferSize) {
		bufferSize += 1;
		char *newBuffer = realloc(inputBuffer, bufferSize);
		if (!newBuffer) {
			fprintf(stderr, "Error: Memory allocation\n");
			free(inputBuffer);
			exit(1);
		}
		inputBuffer = newBuffer;
	}
	inputBuffer[inputSize] = '\0';
	return inputBuffer;
}

