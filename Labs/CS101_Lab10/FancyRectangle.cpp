// TODO: add your code to this file
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void) {
	// Strategy 
	// - prompt for number of rows, columns and a special character to designate box edges
	printf("Number of rows: ");
	int numRows, numColumns;
	scanf("%i" , &numRows);
	
	printf("Number of columns: ");
	scanf("%i", &numColumns);
	
	printf("Special character: ");
	char special;
	scanf(" %c", &special);
	
	// - print solid rectangle of given size
	for (int i = 1; i <= numRows; i++) {
		for (int j = 1; j <= numColumns; j++) {
			if (i == 1) {
				printf(". ");
			
			// - print top left corner of rectangle
			// - 1 row in and 1 column in
			} else if ((i == 2) && (j == 2)) {
				printf("%c ", special);
			} else if ( j == 1) {
				printf(". ");
				
			// - print top right corner of rectangle
			// - 1 row in and 1 column from end
			}else if ((i == 2) && (j == (numColumns - 1))) {
				printf("%c ", special);
				
			// - print bottom left corner of rectangle
			// - 1 row from end and 1 column in
			} else if ((i == (numRows - 1)) && (j == 2)) {
				printf("%c ", special);
				
			// - print bottom right corner of rectangle
			// - 1 row from end and 1 column from end
			} else if ((i == (numRows - 1)) && (j == (numColumns - 1))) {
				printf("%c ", special);
			} else {
				printf(". ");
			}
		}
		printf("\n");
	}

	return 0;
	}