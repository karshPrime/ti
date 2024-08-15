
#include "ticolour.h"
#include <windows.h>

void set_color(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void reset_color() {
    set_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void dark_red(char** aText) {
    set_color(FOREGROUND_RED);
    printf("%s\n", *aText);
    reset_color();
}

void dark_blue(char** aText) {
    set_color(FOREGROUND_BLUE);
    printf("%s\n", *aText);
    reset_color();
}

void dark_green(char** aText) {
    set_color(FOREGROUND_GREEN);
    printf("%s\n", *aText);
    reset_color();
}

void light_red(char** aText) {
    set_color(FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("%s\n", *aText);
    reset_color();
}

void light_blue(char** aText) {
    set_color(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("%s\n", *aText);
    reset_color();
}

void light_green(char** aText) {
    set_color(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("%s\n", *aText);
    reset_color();
}

