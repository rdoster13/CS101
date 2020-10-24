#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Console.h"

// Default frames per second.
#define FPS 10

// Max segments for snake
#define MAX_SEGMENTS 100

//Values defined for direction comparison
#define UP    0
#define DOWN  1
#define RIGHT 2
#define LEFT  3

// Define other struct types, e.g., struct Point, struct Snake
struct Point {
	// coordinates for various functions
	int x, y;
};

struct Snake {
	struct Point segments[MAX_SEGMENTS];
	// how many segments snake has
	int num_segments;
	// which direction the snake is moving in 
	int dir;
};

struct Fruit {
	// Assign random values for fruit
	int x = ((rand() % cons_get_screen_width()) + 1);
	int y = ((rand() % cons_get_screen_height()) + 1);
};

struct Scene {
	// TODO: add fields
	struct Snake snake;
	// add fruit and score fields
	int score;
	struct Fruit fruit;
	// Add flag for "game over"
	bool flag = false;
	
};

// TODO: define functions to operate on your struct types

void scene_init(struct Scene *s);
void scene_render(const struct Scene *s);
int scene_update(struct Scene *s);
void scene_delay(struct Scene *s, int speed);

void snake_remove_tail(struct Snake *snake);
void point_init(struct Point *p, int x, int y);
void snake_init(struct Snake *snake);
void snake_append_head(struct Snake *snake, int x, int y);
struct Point snake_get_head(const struct Snake *snake);
struct Point snake_get_segment(const struct Snake *snake, int index);


int main(void) {
	
	
	// Determine game speed
	printf("GAME SPEED? (slow = 1 / med = 2/ fast = 3)");
	int speed;
	scanf("%i", &speed);
	
	struct Scene scene;
	
	scene_init(&scene);

	int keep_going = 1;
	while (keep_going == 1) {
		scene_render(&scene);
		cons_update();
		scene_delay(&scene, speed);
		keep_going = scene_update(&scene);
	}

	return 0;
}

void scene_init(struct Scene *s) {
	srand(time(0));

	// TODO: add your code
	snake_init(&s->snake);
}

void scene_render(const struct Scene *s) {
	// render the scene
	// clear the screen
	cons_clear_screen();
	
	//generate random seed for fruit
	srand(time(0));
	
	// center cursor on snake segments
	for (int i = 0; i < s->snake.num_segments; i++){
		cons_move_cursor(s->snake.segments[i].y,s->snake.segments[i].x);
		// set snake color
		cons_change_color(GREEN+INTENSE, BLACK);
		// Render Game over if flag is triggered
		if (s->flag == true) {
			cons_move_cursor((cons_get_screen_height()/2)-1,cons_get_screen_width()/2);
			cons_change_color(BLACK, GREEN+INTENSE);
			cons_printw("                   \n");
			cons_move_cursor((cons_get_screen_height()/2),cons_get_screen_width()/2);
			cons_change_color(GREEN + INTENSE, BLACK);
			cons_printw("    GAME OVER!!!   ");
			cons_move_cursor((cons_get_screen_height()/2)+1,cons_get_screen_width()/2);
			cons_change_color(BLACK, GREEN+INTENSE);
			cons_printw("                   \n");
		// draw actual snake parts
		} else if (i < s->snake.num_segments - 1){
			cons_printw("*");
		} else {
			cons_printw("X");
		}
		// Display the score
		cons_move_cursor(cons_get_screen_height(),5);
		cons_printw("SCORE: %i/1000", s->score);
		
		// Display the number of segements
		cons_move_cursor(cons_get_screen_height(),cons_get_screen_width() - 20);
		cons_printw("SEGMENTS: %i/100", s->snake.num_segments);
		
		// Draw fruit
		cons_move_cursor(s->fruit.y,s->fruit.x);
		cons_change_color(RED+INTENSE, BLACK);
		cons_printw("@");
	}
}

int scene_update(struct Scene *s) {
	// Add new head to snake to induce movement
	snake_append_head(&s->snake, snake_get_head(&s->snake).x, snake_get_head(&s->snake).y);
	
	// Remove end of snake tail to keep snake consistent
	snake_remove_tail(&s->snake);
	
	// check for keypresses
	int key = cons_get_keypress();
	
	// Set score value
	s->score = s->snake.num_segments * 10;
	
	
	// Check to see if snake head has reached border
	// Set flag to true if snake reached border 
	
	for (int i = 0; i < s->snake.num_segments; i++){
		if (s->snake.segments[i].y < 1){
			s->flag = true;
		} else if (s->snake.segments[i].x < 1){
			s->flag = true;
		} else if (s->snake.segments[i].y > cons_get_screen_height() - 1){
			s->flag = true;
		} else if (s->snake.segments[i].x >cons_get_screen_width() - 1){
			s->flag = true;
		// Set flag to true if snake runs into itself
		} else if (s->snake.segments[s->snake.num_segments - 1].x == s->snake.segments[i-1].x){
			if (s->snake.segments[s->snake.num_segments - 1].y == s->snake.segments[i-1].y){
				s->flag = true;
			}
		// Check if snake head "eats" fruit
		} else if (s->snake.segments[s->snake.num_segments - 1].x == s->fruit.x){
			if (s->snake.segments[s->snake.num_segments - 1].y == s->fruit.y) {
				// Add segment to snake if it "eats" fruit
				snake_append_head(&s->snake, snake_get_head(&s->snake).x, snake_get_head(&s->snake).y);
				// Generate next fruit in random location
				s->fruit.x = ((rand() % cons_get_screen_width()) + 1);
				s->fruit.y = ((rand() % cons_get_screen_height()) + 1);
				// Check if fruit is in same place as body of snake
				// If so, regenerate fruit
				if (s->fruit.x == s->snake.segments[i-1].x){
					if (s->fruit.y == s->snake.segments[i-1].y){
						s->fruit.x = ((rand() % cons_get_screen_width()) + 1);
						s->fruit.y = ((rand() % cons_get_screen_height()) + 1);
					}
				}
				// Make sure fruit doesn't generate out of bounds
				if ((s->fruit.x <= 2) || (s->fruit.y <=2)){
					s->fruit.x = ((rand() % cons_get_screen_width()) + 1);
					s->fruit.y = ((rand() % cons_get_screen_height()) + 1);
				} else if ((s->fruit.x > cons_get_screen_width() - 3) || (s->fruit.y > cons_get_screen_height() - 3)){
					s->fruit.x = ((rand() % cons_get_screen_width()) + 1);
					s->fruit.y = ((rand() % cons_get_screen_height()) + 1);
				}
			}
		}
	}
	// Change direction based non key pressed
	// Make sure snake can't go opposing directions
	if ((s->snake.dir == 1) && (key == UP_ARROW)){
		s->snake.dir = 1;
		return 1;
	} else if ((s->snake.dir != 1) && (key == UP_ARROW)){
		s->snake.dir = 0;
		return 1;
	} else if ((s->snake.dir == 0) && (key == DOWN_ARROW)){
		s->snake.dir = 0;
		return 1;
	} else if ((s->snake.dir != 0) && (key == DOWN_ARROW)){
		s->snake.dir = 1;
		return 1;
	} else if ((s->snake.dir == 3) && (key == RIGHT_ARROW)){
		s->snake.dir = 3;
		return 1;
	} else if ((s->snake.dir != 3) && (key == RIGHT_ARROW)) {
		s->snake.dir = 2;
		return 1;
	} else if ((s->snake.dir == 2) && (key == LEFT_ARROW)){
		s->snake.dir = 2;
		return 1;
	}else if ((s->snake.dir != 2) && (key == LEFT_ARROW)){
		s->snake.dir = 3;
		return 1;
	} else if ((key == 'q') || (key == 'Q')){
		// This function should return 0 if the player presses 'q',
		return 0;
	} else {
		// 1 otherwise.
		return 1;
	}
	

}

void scene_delay(struct Scene *s, int speed) {
	// This function determines how many milliseconds the game is
	// paused between each frame of animation.
	// You can modify this if you want to vary the game speed.
	// Prompt user for speed options
	
	if (speed == 1){
		cons_sleep_ms(1000/FPS);
	} else if (speed == 2){
		cons_sleep_ms(700/FPS);
	} else if (speed == 3){
		cons_sleep_ms(300/FPS);
	}
};

void snake_remove_tail(struct Snake *snake) {
	for (int i = 1; i < snake->num_segments; i++) {
		snake->segments[i-1] = snake-> segments[i];
	}
	snake->num_segments --;
};

void point_init(struct Point *p, int x, int y){
	x = p->x;
	y = p->y;
};

void snake_init(struct Snake *snake){
	snake->num_segments = 8;
	for (int i = 0; i < snake->num_segments; i++){
		snake->segments[i].y = (cons_get_screen_height() / 2);
		snake->segments[i].x = (cons_get_screen_width() / 2) + i;
	}
	snake->dir = 2;
};

void snake_append_head(struct Snake *snake, int x, int y){
	
	for (int i = 1; i < snake->num_segments; i++) {
		if (snake->dir == 0){
			y = snake->segments[snake->num_segments-1].y - 1;
		} else if (snake->dir == 1){
			y = snake->segments[snake->num_segments-1].y + 1;
		} else if (snake->dir == 2){
			x = snake->segments[snake->num_segments-1].x + 1;
		} else if (snake->dir == 3){
			x = snake->segments[snake->num_segments-1].x - 1;
		}
	}	
	snake->num_segments ++;
	snake->segments[snake->num_segments-1].x = x;
	snake->segments[snake->num_segments-1].y = y;
	
	
};

struct Point snake_get_head(const struct Snake *snake){
	struct Point head;
	head.x = snake->segments[snake->num_segments-1].x;
	head.y = snake->segments[snake->num_segments-1].y;
	return head;	
};

struct Point snake_get_segment(const struct Snake *snake, int index){
	struct Point segment;
	for(int i = 0; i < snake->num_segments; i++){
		segment.x = snake->segments[snake->num_segments - 2].x;
		segment.y = snake->segments[snake->num_segments - 2].y;
	}
	return segment;
};