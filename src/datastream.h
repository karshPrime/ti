
#pragma once

typedef unsigned int uint;

struct Flags {
	char*	STrigger;
	char*	LTrigger;
	void	(*Action)(char**);
};

