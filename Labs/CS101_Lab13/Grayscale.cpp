#include <stdio.h>
#include "Image.h"
#include <math.h>

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
	// - transform RGB array values to be an integer close to given values
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			// - set each pixel to be equal amounts of each color
			int gray = ((0.31 * red[i][j]) + (0.50 * green[i][j]) + (0.19 * blue[i][j]));
			red[i][j] = gray;
			green[i][j] = gray;
			blue[i][j] = gray;
		}
	}
	
	WriteImage("grayscale.bmp", red, green, blue);
	printf("Done writing image\n");

	return 0;
}
