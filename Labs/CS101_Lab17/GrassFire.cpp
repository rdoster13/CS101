#include <stdio.h>
#define MAX 100

// TODO: add function prototypes
void read_cells(int cells[MAX], int num_cells);
void print_cells(int cells[MAX], int num_cells);
void update_cells(int cells[MAX], int num_cells);
void copy_cells(int cells[MAX], int num_cells);

int main(void) {
	// Strategy
	// - prompt user for number of desired cells
	printf("How many cells? ");
	int num_cells, num_generations;
	scanf("%i \n" , &num_cells);
	
	// - prompt user for state of each cells
	int* cells[MAX];
	read_cells(cells[num_cells], num_cells);
	print_cells(cells[num_cells], num_cells);
	
	// - prompt user for number of generations
	printf("How many generations? ");
	scanf("%i ", &num_generations);
	
	for (int i = 0; i < num_generations; i++){
		// - print states for given number of generations
		print_cells(cells[MAX], num_cells);
		
		// - update next generation of spreading fire
		update_cells(cells[MAX], num_cells);
		
		// - copy next state of generation to current state
		copy_cells(cells[MAX], num_cells);
		
		// - print state of cells
		print_cells(cells[MAX], num_cells);
	}
	return 0;
}

// TODO: add function definitions
void read_cells(int cells[MAX], int num_cells){
	// - use loop to read values into cells array
	for (int i = 0; i < num_cells; i++) {
		scanf("%i", &cells[i]);
	}
}

void print_cells(int cells[MAX], int num_cells){
	// - assign print representaions for the values
	for(int i = 0; i < num_cells; i++){
		if (cells[i] == 0){
			printf(",");
		}else if (cells[i] == 1){
			printf("*");
		}
	}
}

void update_cells(int cells[MAX], int num_cells){
	// - implement temp array to store next state
	// - implement first time step, setting fire to surrounding grass
	for(int i = 0; i < num_cells; i++) {
		int dest[MAX];
		if (cells[i] == 0){
			if ((cells[i-1] == 1) || (cells[i+1] == 1)){
					dest[i] = 1;
			}
		} else {
			dest[i] = cells[i];
		}	
		cells[i] = dest[i];
	}
}

void copy_cells(int cells[MAX], int num_cells){
	// - copy state of next array into source array
	int dest[MAX];
	dest[MAX] = cells[MAX];
	cells[MAX] = dest[MAX];
}