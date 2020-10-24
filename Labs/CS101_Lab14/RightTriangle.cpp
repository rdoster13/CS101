#include<stdio.h>
#include<stdbool.h>


/* function prototypes */
void print_spaces(int num_spaces);
void print_line(int line_length);


int main(void) {

    // - implement print_line function 
	// - prompts user to enter height of triangle 
	// - make sure height of triangle is equal to the number of lines to be printed
	printf("Enter the height for your triangle: ");
	int triangle_height;
	scanf("%i", &triangle_height);
    
	// - create for loop to repeat number of lines drawn until height is reached
	for (int i = 1; i <= triangle_height; i++) {
			print_spaces(triangle_height - i);
			print_line(i);
			printf("\n");
    }
    return 0;
}


// - prints spaces for the given number of values
void print_spaces(int num_spaces) {
    for (int i=1; i <= num_spaces; i++) {
        printf(" ");
    }
}


// - prints *for given number of values
void print_line(int line_length) {
    for (int i=1; i <= line_length; i++) {
        if (i == 1){
			printf("*");
		} else if (i == line_length) {
			printf("*");
		}
    }
}