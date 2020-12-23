#include "components.h"
#include "entity.h"
#include "interface.h"
#include <ncurses.h>

void create_actor(entity *head, component_lists *components);

int main() {
  init_interface();
  printw("Hello World !!!"); /* Print Hello World		  */
  refresh();                 /* Print it on to the real screen */
  getch();                   /* Wait for user input */
  close_interface();

  return 0;
}

void create_actor(entity *head, component_lists *components) {
  entity *new_entity = create_entity(&head);
  new_entity++;
}