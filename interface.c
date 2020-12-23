#include "interface.h"

void init_interface() {
  initscr();
  int x, y;
  getmaxyx(stdscr, y, x);
  if (y < MIN_WIN_HEIGHT) {
    printf("W: Current terminal height (%d) less than the required (%d)", y, MIN_WIN_HEIGHT);
  }
  if (x < MIN_WIN_WIDTH) {
    printf("W: Current terminal width (%d) less than the required (%d)", y, MIN_WIN_WIDTH);
  }
}

void close_interface() { endwin(); }