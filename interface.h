#ifndef INTERFACE_H
#define INTERFACE_H

#include <ncurses.h>

#define MIN_WIN_WIDTH 80
#define MIN_WIN_HEIGHT 24

// Initializes ncurses windows
void init_interface();

// Cleans up ncurses windows
void close_interface();

#endif