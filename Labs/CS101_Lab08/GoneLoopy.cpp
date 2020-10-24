#include<stdio.h>

int main(void) {
	// Strategy Part 1
	// - initialize variables and take user input for values
	double average_values, final_average;
	double average_overall = 0;
	printf(" Enter a value to include in the average: " );
	scanf("%lf" , &average_values);
	double numValues;
	if (average_values == -1) {
		printf("No values were input \n");
	} else {
		
		// - create while loop for values that exits when -1 is entered
		while (average_values != -1){
			average_overall = (average_overall + average_values);
			numValues = (numValues + 1);
			printf(" Enter a value to include in the average: " );
			scanf("%lf" , &average_values);
			}
		final_average = (average_overall / numValues);
		printf("The average of the %.0lf values input is: %.2lf \n", numValues , final_average);
	}
    
	// Strategy Part 2
	// - prompt user to enter money desired
	double money_desired;
	double money_made = 0;
	printf("How much money do you want (in dollars)? ");
	scanf("%lf", &money_desired);
	
	// - set up while loop to compute compounding money earnings per day
	int day = 0;
	double money_per_day = 0.01;
	while (money_made < money_desired){
		day = (day + 1);
		money_made = (money_made + money_per_day);
		printf("Day %i: Given $%.2lf, you now have $%.2lf \n", day, money_per_day, money_made);		
		money_per_day = (money_per_day * 2);
	}
	printf("On day %i, you will have met (or exceeded) your request got $%.2lf with a total of $%.2lf.", day, money_desired, money_made);
}
