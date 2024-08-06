
#include "commands.h"
#include "printbreak.h"

int main(int argc, char** argv) {
	// break if not sufficient args are provided
	error_missing_args(&argc, 2);

	// for better readability
	char* cmd = argv[1];

	// print help and break if user asking for help
	check_help(&cmd);

	// find action for given command
	// break if unsupported command
	const Action lAction = Actions[get_action_id(&cmd)];
	
	// get data from args and pipe
	Data lData = get_data(&argc, &argv, &lAction.Type);

	// perform requested action
	if (lAction.Type == Transform) {
		lAction.Command.Transform(&lData.Value);
	} else { // lAction.Type == Crypto
		error_missing_args(&argc, 3);
		lAction.Command.Crypto(&lData.Value, &argv[2]);
	}

	// free data
	free_data(&lData);

	return 0;
}

