// TODO: add your code to this file
#include <stdio.h>
#include <math.h>

int main(void) {
	// Strategy
	// - create variables for hours worked and pay rate
	printf("Enter your hours: ");
	double hours_worked;
	scanf("%lf" , &hours_worked);
	
	printf("Enter your hourly rate: ");
	double hourly_rate;
	scanf("%lf" , &hourly_rate);
	
	// - create overtime variables (hours, pay-rate, and overall pay)
	double overtime_hours;
	double overtime_rate = (hourly_rate * 1.5);
	double overtime_pay;
	
	// - create variables for regular pay and gross salary
	double regular_pay;
	double gross_salary;
	
	// - write if statement for having no overtime
	if (hours_worked <= 40) {
		overtime_hours = 0;
		overtime_pay = (overtime_hours * overtime_rate);
		regular_pay = (hours_worked * hourly_rate);
		gross_salary = (overtime_pay + regular_pay);
	} else {
	// - write part of statement for overtime computations
		overtime_hours = (hours_worked - 40);
		overtime_pay = (overtime_hours * overtime_rate);
		regular_pay = (40 * hourly_rate);
		gross_salary = (overtime_pay + regular_pay);
	}
	
	// - print statements representing results
	printf("Number of hours worked: %0.2lfh \n" , hours_worked);
	printf("Hourly rate: $%0.2lf \n" , hourly_rate);
	printf("Overtime hours: %0.2lfh \n" , overtime_hours);
	printf("Overtime rate: $%0.2lf \n" , overtime_rate);
	printf("Regular pay: $%0.2lf \n" , regular_pay);
	printf("Overtime pay: $%0.2lf \n" , overtime_pay);
	printf("Gross salary: $%0.2lf \n" , gross_salary);
}