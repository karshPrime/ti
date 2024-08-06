
#pragma once

void error_invalid_command(const char** aArgument);
void error_missing_args(const int* aProvided, const int aNeeded);
void error_mem_alloc(char** aBuffer);

void print_help();

