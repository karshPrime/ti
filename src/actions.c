
#include "commands.h"
#include "transform.h"
#include "crypto.h"

const Action Actions[] = {
    {
        .STrigger = "-c", .LTrigger = "--case",
        .Command = { .Transform = lower }, .Type = Transform
    },
    {
        .STrigger = "-C", .LTrigger = "--CASE",
        .Command = { .Transform = upper }, .Type = Transform
    },
    {
        .STrigger = "-s", .LTrigger = "--sentence",
        .Command = { .Transform = sentence }, .Type = Transform
    },
    {
        .STrigger = "-w", .LTrigger = "--word",
        .Command = { .Transform = word }, .Type = Transform
    },
    {
        .STrigger = "-r", .LTrigger = "--rotate13",
        .Command = { .Transform = rotate13 }, .Type = Transform
    },
    {
        .STrigger = "-f", .LTrigger = "--flip",
        .Command = { .Transform = flip }, .Type = Transform
    },
    {
        .STrigger = "-m", .LTrigger = "--mock",
        .Command = { .Transform = mock }, .Type = Transform
    },
    {
        .STrigger = "-i", .LTrigger = "--charindx",
        .Command = { .Transform = charindx }, .Type = Transform
    },
    {
        .STrigger = "-a", .LTrigger = "--ascii",
        .Command = { .Transform = ascii }, .Type = Transform
    },
    { 
        .STrigger = "-A", .LTrigger = "--ascii-bin",
        .Command = { .Transform = ascii_bin }, .Type = Transform
    }
};

const uint ActionsCount = sizeof(Actions) / sizeof(Actions[0]);

