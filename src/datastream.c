
/* datastream.c
 * code for parsing input data
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "datastream.h"

Input piped_data() {
	char *inputBuffer = NULL;
	unsigned int bufferSize = 0;
	unsigned int inputSize = 0;
	int ch;

	// Read all piped text
	while ((ch = getchar()) != EOF) {
		if (inputSize >= bufferSize) {
			bufferSize += 256;
			char *newBuffer = realloc(inputBuffer, bufferSize);
			if (!newBuffer) {
				fprintf(stderr, "Memory allocation error\n");
				free(inputBuffer);
				exit(1);
			}
			inputBuffer = newBuffer;
		}
		inputBuffer[inputSize++] = (char)ch;
	}

	// Null-terminate the string
	if (inputSize >= bufferSize) {
		bufferSize += 1;
		char *newBuffer = realloc(inputBuffer, bufferSize);
		if (!newBuffer) {
			fprintf(stderr, "Memory allocation error\n");
			free(inputBuffer);
			exit(1);
		}
		inputBuffer = newBuffer;
	}
	inputBuffer[inputSize] = '\0';

	// Split inputBuffer into strings
	char** values = NULL;
	unsigned int valuesSize = 0;

	char* token = strtok(inputBuffer, " \n");  // Split by space or newline
	while (token != NULL) {
		values = realloc(values, sizeof(char*) * (valuesSize + 1));
		if (!values) {
			fprintf(stderr, "Memory allocation error\n");
			free(inputBuffer);
			exit(1);
		}
		values[valuesSize] = strdup(token);  // Copy token to values array
		if (!values[valuesSize]) {
			fprintf(stderr, "Memory allocation error\n");
			free(inputBuffer);
			for (unsigned int i = 0; i < valuesSize; ++i) {
				free(values[i]);
			}
			free(values);
			exit(1);
		}
		valuesSize++;
		token = strtok(NULL, " \n");
	}

	// Clean up the input buffer
	free(inputBuffer);

	struct Input Result = { values, valuesSize };
	return Result;
}

