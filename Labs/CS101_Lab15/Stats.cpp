#include<stdio.h>
#include<math.h>

// TODO: Insert you code here
// - call prototype functions for operations
double mean(int num1, int num2, int num3, int num4);
double stddev(int num1, int num2, int num3, int num4);
int max(int num1, int num2, int num3, int num4);
int min(int num1, int num2, int num3, int num4);

int main(void) {
	// - declare and prompt for variables
	int num1, num2, num3, num4;
	printf("Enter four integer values : ");
	scanf("%i %i %i %i", &num1, &num2, &num3, &num4);
	printf ("\n");
	
	// - cdeclare variables to store function results
	double mean_result = mean(num1, num2, num3, num4);
	double stddev_result = stddev(num1, num2, num3, num4);
	int max_result = max(num1, num2, num3, num4);
	int min_result = min(num1, num2, num3, num4);
	
	printf("The mean of your values is %.2lf \n", mean_result);
	printf("The standard deviation of your values is %.2lf \n", stddev_result);
	printf("The max of your values is %i \n", max_result);
	printf("The min of your values is %i \n", min_result);
	
	
}

double mean(int num1, int num2, int num3, int num4){
	double result;
	
	// - Compute mean of integer values
	result = (num1 + num2 + num3 + num4) / 4.00; 
	return result;
}

double stddev(int num1, int num2, int num3, int num4){
	double result;
	
	// -find mean of numbers in set
	double mean = (num1 + num2 + num3 + num4) / 4.0;
	double diff1, diff2, diff3, diff4;
	
	diff1 = pow((num1 - mean), 2);
	diff2 = pow((num2 - mean), 2);
	diff3 = pow((num3 - mean), 2);
	diff4 = pow((num4 - mean), 2);
	
	double final_stddev = sqrt((diff1 + diff2 + diff3 + diff4) / 4.0);
	
	result = final_stddev;
	return result;
}

int max(int num1, int num2, int num3, int num4){
	int result;
	if ((num1 > num2) &&(num1 > num3) && (num1 > num4)) {
		result = num1;
	} else if ((num2 > num1) &&(num2 > num3) && (num2 > num4)) {
		result = num2;
	} else if ((num3 > num1) &&(num3 > num2) && (num3 > num4)) {
		result = num3;
	} else if ((num4 > num1) &&(num4 > num2) && (num4 > num3)) {
		result = num4;
	}
		
	return result;
}

int min(int num1, int num2, int num3, int num4){
	int result;
	if ((num1 < num2) &&(num1 < num3) && (num1 < num4)) {
		result = num1;
	} else if ((num2 < num1) &&(num2 < num3) && (num2 < num4)) {
		result = num2;
	} else if ((num3 < num1) &&(num3 < num2) && (num3 < num4)) {
		result = num3;
	} else if ((num4 < num1) &&(num4 < num2) && (num4 < num3)) {
		result = num4;
	}
		
	return result;
}