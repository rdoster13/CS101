// TODO: add your code to this file
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define NUM 10
#define EMPTY 0
#define UPRIGHT 1
#define TIPPING 2
#define HORIZ 3


int main(void) {
	
	// - Stategy
	// - initialize array to store states
	int state[NUM];
	int next_state[NUM];
	
	// - read & print initial state
	for(int i = 0; i < NUM; i++) {
		printf("Position %i (0=empty, 1=upright, 2=tipping, 3=horizontal): ", i + 1);
		scanf("%i", &state[i]);
	}
	printf("\n \n");
	
	// - print time 0 state
	printf("Initial configuration \n");
	for (int i = 0; i < NUM; i++) {
		if (state[i] == EMPTY) {
			printf(" ");
		} else if (state[i] == UPRIGHT) {
			printf("|");
		} else if (state[i] == TIPPING) {
			printf("/");
		}else if (state[i] == HORIZ) {
			printf("_");
		}
	}
	printf("\n \n");
	
	// - if fist state is upright, change to "ready to tip" to initiate fall
	printf("Tipping over domino  0: \n");
	for (int i = 0; i < NUM; i++) {
		if (state[0] == UPRIGHT) {
			state[0] = TIPPING;
		}
		if (state[i] == EMPTY) {
			printf(" ");
		} else if (state[i] == UPRIGHT) {
			printf("|");
		} else if (state[i] == TIPPING) {
			printf("/");
		}else if (state[i] == HORIZ) {
			printf("_");
		}
	}
	printf("\n \n");
	int RTT = 0;
	// - for time states 1 - 10, update & print
	for (int j = 0; j < 10; j++) {
		printf("Time step %i \n", j+1);
		for (int i = 0; i < NUM; i++) {
			next_state[i] = state[i];
			if (state[i] == TIPPING) {
				next_state[i] = HORIZ;
				RTT = 1;
			}else if (state[i] == UPRIGHT) {
				if ((state[i-1] == HORIZ) && (RTT == 1)) {
					next_state[i] = TIPPING;
				} else {
					RTT = 0;
				}
			} else {
				RTT =0;
			}
			state[i] = next_state[i];
		}
		for (int i = 0; i < NUM; i++){			
			if (state[i] == EMPTY) {
				printf(" ");
			} else if (state[i] == UPRIGHT) {
				printf("|");
			} else if (state[i] == TIPPING) {
				printf("/");
			}else if (state[i] == HORIZ) {
				printf("_");
			} 
		}
		printf(" \n");
	}

}