// TODO: add your code to this file
#include <stdio.h>

int main(void) {
	//Strategy	
	// - prompt user for first double value
	printf("Enter first decimal value \n");
	double v1;
	scanf("%lf", &v1);

	// - prompt user for second double value
	printf("Enter second decimal value \n");
	double v2;
	scanf("%lf", &v2);
	
	// - compute/print sum, difference, product, and quotient
	double sum = (v1 + v2);
	double difference = (v1 - v2);
	double product = (v1 * v2);
	double quotient = (v1 / v2);
	printf("%0.3lf + %0.3lf = %0.3lf \n" , v1, v2, sum);
	printf("%0.3lf - %0.3lf = %0.3lf \n" , v1, v2, difference);
	printf("%0.3lf * %0.3lf = %0.3lf \n" , v1, v2, product);
	printf("%0.3lf / %0.3lf = %0.3lf \n" , v1, v2, quotient);
	
	// - prompt user for first integer values
	printf("Enter first integer value \n");
	int in1;
	scanf("%i", &in1);

	// - prompt user for second integer value
	printf("Enter second integer value \n");
	int in2;
	scanf("%i", &in2);
	
	// - compute/print int division quotient and modulus
	int quotient_int = (in1 / in2);
	int modulus_int = (in1 % in2);
	printf("%i / %i = %i \n" , in1 , in2 , quotient_int);
	printf("%i %% %i = %i \n" , in1 , in2 , modulus_int);

	// - print end thank you statement
	printf("Thank you for using the expensive calculator.");

	return 0;
}