// TODO: add your code to this file
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

 

int main(void) {
	// Strategy
	// - seed random number generator
	srand(time(0));
	
	// - initialize variable to allow re-play and set to 1 to trigger play-through
	int play_again = 1;
	
	// - initialize games played and won
	double games_played = 0; 
	double games_won = 0;
	while (play_again == 1) {
		// - assign car to a random door 1-3
		int car = (rand() % 3) + 1;
		
		// - Prompt user to pick a door 1-3
		printf("Which door would you like to pick? (1-3) ");
		int player_choice;
		scanf("%i" , &player_choice);
		
		// - show user which door Monty chose
		// - make sure the door chosen is not the car
		// - make sure the door chosen by Monty isn't the same as player choice
		int monty_choice = (rand() % 3) + 1;
		while ( (monty_choice == car) || (monty_choice == player_choice )) {
			monty_choice = (rand() % 3) +1;
			}
		printf("Monty shows you a goat behind door number %i \n" , monty_choice);
		
		// - ask user if they want to switch doors
		printf("Which door would you like to pick now? ");
		scanf("%i" , &player_choice);
		
		// - print result of player end choice / reveal where car was
		// - update amount of games played and won
		if ( player_choice == car ) {
			printf("You won the car! \n");
			games_won = (games_won + 1);
			games_played = (games_played + 1);
		} else {
			printf("You got a goat, sorry. the car was behind door %i \n" , car);
			games_played = (games_played + 1);
		}
		printf("Another game? (1=yes, 0=no)");
		scanf("%i", &play_again);
		
	}
	
	printf("You won %.0lf games \n" , games_won);
	

	// - compute/display percentage of games won
	double percent_won = ((games_won / games_played) * 100);
	printf("You won %.2lf %% of the games \n" , percent_won);
}