
#include "commands.h"
#include "printbreak.h"

int main(int argc, char** argv) {
	// break if not sufficient args are provided
	error_missing_args(&argc);

	// for better readability
	const char* CMD = argv[1];

	// print help and break if user asking for help
	check_help(&CMD);

	// find action for given input; break for unsupported input 
	Call cAction = get_action(&CMD);
	
	// get data from args and pipe
	Data lData = get_data(&argc, &argv);

	// perform requested action
	cAction(&lData.Value);

	// free data
	free_data(&lData);

	return 0;
}

