#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int dispInt;
	printf("Enter an integer: ");
	scanf("%d", &dispInt);

	// This is a 3d array, storing in each segments[i] the seven segment display for integer i.
	const char segments[10][3][3] = {{{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'} } , {{' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}}, {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}},{{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}}, {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}}, {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}}, {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}}, {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}}, {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}}, {{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}}};

	// This chunk of code counts the number of digits in the integer
	// with the added condition that if the int is 0, then it has 1 digit
	unsigned int digits;
	int k = dispInt;
	int  dispNeg = 0;
	
	if (dispInt <  0)  k = -dispInt;
	
	if (k == 0) digits = 1;
	else digits = 0;
	while (k > 0) {
		digits++;
		k /= 10;
	}

	// reset k to displayInt because we need it again
	if (dispInt < 0) k = -dispInt;
	else k = dispInt;
	unsigned int n = digits;
	//this chunk of code stores the digits in an array
	char arr[digits];
	while (digits--) {
		arr[digits] = k%10;
		k /= 10;
	}	

	// create a 2d array that will display the segments
	char dispSegments[3][n*3];

	int a,b = 0;
	int c = 0;
	int i,j = 0;
	// This nested for loop takes the elements from the 3d segment array and stores them in a 2d array
	// this was necessary to get the numbers to print on the same line
	for (i = 0; i < 3; i++) {

		for (j = 0; j < n*3; j++) {
				
			// Notice that it's arr[a] in segments, this will pick the correct digit from segments
			dispSegments[i][j] = segments[arr[a]][b][c];
			printf("%c", dispSegments[i][j]);
			// We need to increase a,b and c differently because segments has different dimensions than dispSegments
			c++;
			if (c == 3) {
				c = 0;
				a++;
			}
		}
		c = 0;
		a = 0;
		b++;
		printf("\n");
	}


	char choice;
	printf("Do you want to enter another Integer? (Y/N): ");
	scanf(" %c", &choice);
	if (choice == 'Y')
		main();
	else exit;
}	 
