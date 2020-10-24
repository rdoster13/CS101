#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// Function prototypes go here.
int addInts(int a, int b);

// - add prototypes for extra funtions
int roundToNearest100(int a);
bool isOdd(int a);
double poly(double x);
double celsiusToFahrenheit(double t);

int main(void) {
	// Tests for each function go here
	assert(addInts(4, 5) == 9);
	assert(addInts(0, 11) == 11);
	assert(addInts(4, -19) == -15);
	assert(addInts(-4, -9) == -13);
	
	// - Testing roundToNearest100
	assert(roundToNearest100(137) == 100);
	assert(roundToNearest100(167) == 200);
	assert(roundToNearest100(447) == 400);
	assert(roundToNearest100(717) == 700);
	
	// - testing isOdd
	assert(isOdd(9) == true);
	assert(isOdd(26) == false);
	assert(isOdd(2) == false);
	assert(isOdd(11) == true);
	
	// - testing poly
	assert(poly(3) == 57);
	assert(poly(4) == 84);
	assert(poly(10) == 372);
	assert(poly(89) == 24309);
	
	// - testing celsiusToFahrenheit
	assert(celsiusToFahrenheit(0) == (0 * (9.0/5.0) + 32));
	assert(celsiusToFahrenheit(100) == (100 * (9.0/5.0) + 32));
	assert(celsiusToFahrenheit(50) == (50 * (9.0/5.0) + 32));
	assert(celsiusToFahrenheit(37) == (37 * (9.0/5.0) + 32));
	

	printf("All tests passed!\n");
	return 0;
}

int addInts(int a, int b) {
	int sum;
	sum = a + b;
	return sum;
}
// - initialize each of the four additional functions

int roundToNearest100(int a){
	int nearest100;
	// - make number 2 digits to analyze tens place
	a = a / 10;
	if (a % 10 < 5){
		// - force number to truncate to only hundred digit
		nearest100 = a / 10;
		// - multiply to make number even hundred(s)
		nearest100 = nearest100 * 100;
	} else if (a % 10 > 5){
		// - after truncating, increase hundred digit by 1
		nearest100 = (a / 10) + 1;
		// - make number even hundred(s)
		nearest100 = nearest100 * 100;
	}
	return nearest100;
}

bool isOdd(int a) {
	// - if divisible by 2, return  true
	if (a % 2 == 1) {
		return true;
	} else {
		return false;
	}
}

double poly(double x){
	double polynomial;
	
	// - compute polynomial 
	polynomial = ((3 * (x * x)) + (6 * x) + 12);
	
	return polynomial;
}

double celsiusToFahrenheit(double t){
	double newTemp;
	// - compute celcius to fahrenheit conversion
	newTemp = (t * (9.0/5.0) +32);
	
	return newTemp;
}