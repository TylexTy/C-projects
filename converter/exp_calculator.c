/* A program that takes in a base and exponent and calculates the value
 *
 * Author: Tyler Bulley
 *
 * UWO ID: 250498520
 *
 * */


#include <stdio.h>

float expCalc(float base, int exponent); // declaring the function before using it

int main() {

	float base;
	int exponent;

	printf("Please enter a base number to be exponentiated: ");
	scanf("%f", &base);
	if (base <= 0) {  // only want numbers greater than 0
		main(); // return to start of program
	}
	printf("\nPlease enter an exponent for the base: ");
	scanf("%d", &exponent);
	if (exponent >= 0)
		printf("%.2f to the power of %d is %.2f\n", base, exponent, expCalc(base, exponent));
	else 
		printf("%.2f to the power of %d is %.2f\n", base, exponent, 1.00/expCalc(base,-exponent));
	
	return 0;

}

float expCalc(float base, int exponent) {

	if (exponent == 0) {

		return 1; // our base case 
	}	

	if (exponent % 2 == 0) { // recursive call when we have even exponent
	
		return (expCalc(base, exponent/2) * expCalc(base,exponent/2));	
				
	}
	else { // recursive call when we have odd exponent

		return (expCalc(base, (exponent-1)/2) * expCalc(base, (exponent-1)/2) * base);
	}
}
