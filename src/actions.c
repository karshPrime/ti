
#include "commands.h"
#include "transform.h"
#include "colour.h"

const Action Actions[] = {
	// transform commands
    { "-c",  "--case",   lower },
    { "-C",  "--CASE",  upper },
    { "-s",  "--sentence",  sentence },
    { "-w",  "--word",  word },
    { "-r",  "--rotate13",  rotate13 },
    { "-f",  "--flip",  flip },
    { "-m",  "--mock",  mock },
    { "-i",  "--charindx",  charindx },
    { "-a",  "--ascii",  ascii },
    { "-a",  "--ascii-bin",  ascii_bin },

	// colour commands
	{ "-dr", "--dark-red",  dark_red },
	{ "-db", "--dark-blue",  dark_blue },
	{ "-dg", "--dark-green",  dark_green },
	{ "-lr", "--light-red",  light_red },
	{ "-lb", "--light-blue",  light_blue },
	{ "-lg", "--light-green",  light_green }
};
const uint ActionCount = sizeof(Actions) / sizeof(Actions[0]);

