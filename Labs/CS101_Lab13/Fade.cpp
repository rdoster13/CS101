#include <stdio.h>
#include <math.h>
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

int main(void)
{
	ReadImage("kitten.bmp", red, green, blue);

	// Strategy
	// - declare variables for fade	
	double fade, hdist, vdist;
	// - transform RGB array values to be an integer close to given values
	for (int i = 0; i < WIDTH; i++) {
		hdist = (i + 1.0) / WIDTH;
		for (int j = 0; j < HEIGHT; j++) {
			// - calculate pixel distances 
			vdist = (j + 1.0) / HEIGHT;
			// - compute fade based on pixel distance
			fade = sin(hdist * M_PI) * sin(vdist * M_PI);
			// - set each pixel to change color based on fade computation
			// - declare variables to store n
			int fade_red = fade * red[i][j];
			int fade_green = fade * green[i][j];
			int fade_blue = fade * blue[i][j];
			red[i][j] = fade_red;
			green[i][j] = fade_green;
			blue[i][j] = fade_blue;
		}
	}

	WriteImage("fade.bmp", red, green, blue);
	printf("Done writing image\n");

	return 0;
}
