#include <stdio.h>
#include <math.h>

int main(void) {
    //Strategy
	// - create variables for height (meters)
	printf("Enter the initial height of the object in meters: ");
	double height_m;
	scanf("%lf", &height_m);
		
	// - compute/print time to impact (sec)
	double time_to_impact_sec = sqrt((2 * height_m) / 9.81);
	printf("The object took %0.2lf seconds to fall \n", time_to_impact_sec);
	
	// - compute/print velocity (m/sec)
	double velocity_mps = (9.81 * time_to_impact_sec);
	
	// - compute/print velocity (ft/sec)
	double velocity_ftps = ((9.91 * time_to_impact_sec) * 3.28);
	
	// - compute/print velocity (mph)
	double velocity_mph = ((9.91 * time_to_impact_sec) * (3600.0 / 1609.0));
	printf("The velocity of the object at impact was: %4.1lf m/sec \n", velocity_mps);
	printf("                                          %4.1lf ft/sec \n", velocity_ftps);
	printf("                                          %4.1lf mph \n", velocity_mph);

    return 0;
}