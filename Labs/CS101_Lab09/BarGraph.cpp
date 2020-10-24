// TODO: add your code to this file
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
	// Strategy
	// - create while loop to prompt user to draw graph
	char answer  = ('y');
	
	while ((answer == 'y') || (answer == 'Y')){

	// - prompt user for length of bar graph
		int length;
		printf("length? ");
		scanf("%i" , &length);
		
		// - create for loop to draw bar size
		int i;
		for (i = 1; i<= length; i++) {
			printf("=");
		}
		
		// - prompt user to draw another graph
		printf("\n");
		printf("another? ");
		scanf(" %c", &answer);
	}
	return 0;
}