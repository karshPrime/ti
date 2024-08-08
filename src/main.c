
#include "commands.h"
#include "printbreak.h"

int main(int argc, char** argv) {
	// break if not sufficient args are provided
	error_missing_args(&argc);

	// for better readability
	char* cmd = argv[1];

	// print help and break if user asking for help

	// find action for given command
	// break if unsupported command
	const Action lAction = Actions[get_action_id(&cmd)];
	
	// get data from args and pipe
	Data lData = get_data(&argc, &argv);

	// perform requested action
	cAction(&lData.Value);

	// free data
	free_data(&lData);

	return 0;
}

