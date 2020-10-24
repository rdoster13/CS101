#include "Console.h"

// Definition of the Scene struct type
struct Scene {
	// TODO: add fields
	int x, y;
	int dx, dy;
};

// Function prototypes
void scene_init(struct Scene *s);
void scene_render(const struct Scene *s);
void scene_update(struct Scene *s);

// Animatation delay (.1s)
#define ANIMATION_DELAY (1000/10)

int main(void) {
	struct Scene myScene;

	// TODO: add call to scene_init
	scene_init(&myScene);

	int keep_going = 1;
	while (keep_going == 1) {
		// clear the off-screen display buffer
		cons_clear_screen();

		// render the scene into the display buffer
		// TODO: add call to scene_render
		scene_render(&myScene);

		// copy the display buffer to the display
		cons_update();

		// pause
		cons_sleep_ms(ANIMATION_DELAY);

		// update the scene
		// TODO: add call to scene_update
		scene_update(&myScene);

		// see if the user has pressed a key
		int key = cons_get_keypress();
		if (key != -1) {
			keep_going = 0;
		}
	}

	return 0;
}

// TODO: add definitions for scene_init, scene_render, and scene_update
void scene_init(struct Scene *s){
	// - intitialize fields
	s -> x = 0;
	s -> y = 0;
	s -> dx = 1;
	s -> dy = 1;
	
}

void scene_render(const struct Scene *s){
	// - render the scene
	cons_clear_screen();
	cons_move_cursor(s->y, s->x);
	cons_change_color(BLUE+INTENSE, BLACK);
	cons_printw("$");

}

void scene_update(struct Scene *s){
	// TODO: update the scene with consistent direction for x
	if(s->dx == 1){
		s->x = (s->x + 1);
	}else if(s->dx == -1){
		s->x = (s->x - 1);
	}
	
	// TODO: update the scene with consistent direction for x
	if(s->dy == 1){
		s->y = (s->y + 1);
	}else if(s->dy == -1){
		s->y = (s->y - 1);
	}
	
	// - DETECT wall and "bounce" other direction for x
	if (s->x == 0) {
		s->dx = 1;
	} else if (s->x == cons_get_screen_width() - 1){
		s->dx = -1;
	}
	
	// - DETECT wall and "bounce" other direction for y
	if (s->y == 0) {
		s->dy = 1;
	} else if (s->y == cons_get_screen_height() - 1){
		s->dy = -1;
	}
}