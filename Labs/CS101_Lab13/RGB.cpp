#include <stdio.h>
#include "Image.h"

// Arrays to store image color component data.
// Note that it is normally not a good practice to define
// variables/arrays in the global scope.  However, because
// these arrays have a large number of elements, they
// are too large to define within a function (such as main)
// on some systems.
int red[WIDTH][HEIGHT];
int green[WIDTH][HEIGHT];
int blue[WIDTH][HEIGHT];
int red_out[WIDTH*2][HEIGHT*2];
int green_out[WIDTH*2][HEIGHT*2];
int blue_out[WIDTH*2][HEIGHT*2];

int main(void)
{
	ReadImage("kitten.bmp", red, green, blue);

	// TODO: transform data, storing transformed data in
	//       the red_out, green_out, and blue_out arrays
	
	// - use loops to change all values of red_out, blue_out, and green_out
	// - use loop for red picture
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			red_out [i][j] = red[i][j];
		}
	}
	
	// - use loop for green picture
	// - off center by one picture width
	for (int i = WIDTH; i < WIDTH * 2; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			green_out [i][j] = green[i-WIDTH][j];
		}
	}
	
	// - use loop for blue picture
	// - off center by one picture height
	for (int i = 0; i < WIDTH; i++) {
		for (int j = HEIGHT; j < HEIGHT * 2; j++) {
			blue_out [i][j] = blue[i][j-HEIGHT];
		}
	}
	// - use loop to recreate original picture
	// - off center by one picture width and hei./ght
	for (int i = WIDTH; i < WIDTH * 2; i++) {
		for (int j = HEIGHT; j < HEIGHT * 2; j++) {
			red_out[i][j] = red[i-WIDTH][j-HEIGHT] ;
			green_out[i][j] = green[i-WIDTH][j-HEIGHT];
			blue_out[i][j] = blue[i-WIDTH][j-HEIGHT];
		}
	}

	WriteDoubleSizeImage("rgb.bmp", red_out, green_out, blue_out);
	printf("Done writing image\n");

	return 0;
}
