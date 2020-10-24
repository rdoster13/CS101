#include "Console.h"

int main(void)
{
	cons_clear_screen();
	
	// Don't change anything above this line

	// TODO: Add your code here
	cons_change_color(CYAN + INTENSE, GRAY);
	cons_move_cursor(12, 32);
	cons_printw("Hello, CS 101!!!");
	

	// Don't change anything below this line
	
	cons_update();
	cons_wait_for_keypress();
	
	return 0;
}
