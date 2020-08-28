#include <ncurses.h>
#include "components.h"
#include "entity.h"

void create_actor(entity *head, component_lists *components);

int main()
{	
	initscr();			/* Start curses mode 		  */
	printw("Hello World !!!");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

	return 0;
}

void create_actor(entity *head, component_lists *components) {
	entity *new_entity = create_entity(&head);
	
}