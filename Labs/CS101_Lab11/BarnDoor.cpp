// TODO: add your code to this file
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void) {
	// Strategy
	// - prompt user for barn door size
	int size;
	printf("What size barn door?" );
	scanf("%i", &size);
	
	// - initialize nested loop to draw structure
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			
			// - print top and bottom borders
			if ((i == 0) || (i == size -1)) {
				printf("-");
			
			// - print left and right borders
			} else if ((j == 0) || (j == size -1)) {
				printf("|");
			
			// - print center X of door
			} else if ((j == (size /2)) && (i == (size / 2))) {
				printf("X");
				
			// - print first diagonal of door (left to right) 
			} else if (j == i) {
				printf("\\");
				
			// - print second diagonal of door (right to left)
			} else if ((size - i) == (j + 1)){
				printf("/");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}	
	
	return 0;
}