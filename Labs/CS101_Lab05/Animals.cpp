// TODO: add your code to this
#include <stdio.h>

int main(void) {
	// Strategy
	// - ask for user input to determine if they are a mammal
	printf("Are you a mammal? (yes = 1, no = 2)\n");
	int player_choice;
	scanf("%i", &player_choice);
	
	// - if they are, ask if they are a marsupial
	if (player_choice == 1) {
		printf("Are you a marsupial? (yes = 1, no = 2)\n");
		scanf("%i" , &player_choice);
		
		// - if they are a marsupial, print they are a kangaroo
		if (player_choice == 1) {
			printf("You are a Kangaroo. \n");
		} else {
			// - if they aren't, print they are a horse
			printf("You are a Horse. \n");
		};
	
	// - if not a mammal, ask if feathers are present
	} else {
		printf("Do you have feathers? (yes = 1, no = 2) \n");
		scanf("%i" , &player_choice);
		
		// - if yes to feathers, player are a magpie
		if (player_choice == 1) {
			printf("You are an Australian magpie. \n");
		} else {
			// - if no feathers, player is a shark		
			printf("You are a shark. \n");
		}
	}
	return 0;
}