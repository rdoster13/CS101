#include "Console.h"

void boing_init(int *px, int *py, int *pdx, int *pdy);
void boing_render(int x, int y);
void boing_update(int *px, int *py, int *pdx, int *pdy);

int main(void) {
	int x, y, dx, dy;

	// initialize variables
	boing_init(&x, &y, &dx, &dy);

	int keep_going = 1;
	while (keep_going == 1) {
		// print the character using x and y as its location
		boing_render(x, y);

		// update the terminal window
		cons_update();

		// update the variables so that the character will appear to move
		// the next time the boing_render function is called
		boing_update(&x, &y, &dx, &dy);

		// See if a key has been pressed
		int key = cons_get_keypress();
		if (key >= 0) {
			keep_going = 0;
		}

		// Pause for a short time
		cons_sleep_ms(1000/10);
	}

	return 0;
}

// TODO: add definitions for boing_init, boing_render, and boing_update
void boing_init(int *px, int *py, int *pdx, int *pdy){
	*px = 0;
	*py = 0;
	*pdx = 1;
	*pdy = 1;
}

void boing_render(int x, int y){
	cons_clear_screen();
	cons_move_cursor(y, x);
	cons_change_color(BLUE+INTENSE, BLACK);
	cons_printw("$");
}

void boing_update(int *px, int *py, int *pdx, int *pdy){
		
	if (*pdy == -1){
		*py = *py - 1;
	} else if  (*pdy == 1){
		*py = *py + 1;
	}
	if (*pdx == -1){
		*px = *px - 1;
	} else if (*pdx == 1){
		*px = *px + 1;
	}
	if (*px == 0) {
		*pdx = 1;
	} else if (*px == 79){
		*pdx = -1;
	}
	if (*py == 0) {
		*pdy = 1;
	} else if (*py == 23){
		*pdy = -1;
	}
}