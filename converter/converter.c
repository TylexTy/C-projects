/* A program that converts various units of measurement
 *
 * Author: Tyler Bulley
 * UWO ID: 250498520
 * */

#include <stdio.h>

void convert(int menuNumber); // Declaring the function before it is used

int main ()
{
        int menuNumber;
        printf("\nWhat would you like to do?\n");
        printf("Press 1 for conversion between Kilometer and Mile\n");
        printf("Press 2 for conversion between Meter and Feet\n");
        printf("Press 3 for conversion between Centimeter and Inch\n");
        printf("Press 4 for conversion between Celsius and Fahrenheit\n");
        printf("Press 5 to Quit\n");
        printf("Enter a number (1-5) : ");

        scanf("%d", &menuNumber);
	convert(menuNumber); // our function below which processes the number picked
	
	return 0;

        
}
/* This function does the converting of units depending on the menu Number selected. */

void convert(int menuNumber) {

	char menuChar;
	float amount;
	char anyKey;
	int ch;

	switch(menuNumber)
        {
                case 1:
                        printf("Enter K for conversion from Kilometer to Mile\n");
                        printf("or enter M for conversion from Mile to Kilometer\n");
                        scanf(" %c", &menuChar);
			while ((ch = getchar()) != '\n' && ch != EOF) {} // This code flushes the buffer and takes only the first entry		
                        if (menuChar == 'K')
                        {
                                printf("Enter the amount in Kilometers to convert to Miles: ");
                                scanf("%f", &amount);
                                float  convAmount = amount * 0.62137;
                                printf("%.2f kilometers is %.2f miles\n", amount, convAmount);

                        }
                        else if (menuChar == 'M')
                        {
                                printf("Enter the amount in Miles to convert to Kilometers: ");
                                scanf("%f", &amount);
                                float convAmount = amount * 1.609344;
                                printf("%.2f miles is %.2f kms\n", amount, convAmount);
                        }
                        else {
                                convert(1); // if it's not K or M, redo the convert function

                        }
			printf("Press any letter for menu: ");
			scanf(" %c", &anyKey); // pres any key to continue
                        main(); // return to the beginning of the program
			break;
                case 2:
                        printf("Enter M for conversion from Meter to Feet\n");
                        printf("or enter F for conversion from Feet to Meter\n");
                        scanf(" %c", &menuChar);
                        if (menuChar == 'M')
                        {
                                printf("Enter the amount in Meters to convert to Feet: ");
                                scanf("%f", &amount);
                                float  convAmount = amount * 3.28084;
                                printf("%.2f meters is %.2f feet\n", amount, convAmount);

                        }
                        else if (menuChar == 'F')
                        {
                                printf("Enter the amount in Feet to convert to Meters: ");
                                scanf("%f", &amount);
                                float convAmount = amount * 0.3048;
                                printf("%.2f feet is %.2f meters\n", amount, convAmount);
                        }
                        else {
                                convert(2);

                        }
			printf("Press any letter for menu: ");
			scanf(" %c", &anyKey);
                        main();
			break;
                case 3:
                        printf("Enter C for conversion form Centimeter to Inch\n");
                        printf("or enter I for conversion from Inch to Centimeter\n");
                        scanf(" %c", &menuChar);
                        if (menuChar == 'C')
                        {
                                printf("Enter the amount in Centimeters to convert to Inches: ");
                                scanf("%f", &amount);
                                float  convAmount = amount * 0.3937;
                                printf("%.2f cm is %.2f in\n", amount, convAmount);

                        }
                        else if (menuChar == 'I')
                        {
                                printf("Enter the amount in Inches to convert to Centimeters: ");
                                scanf("%f", &amount);
                                float convAmount = amount * 2.54;
                                printf("%.2f in is %.2f cm\n", amount, convAmount);
                        }
                        else {
                                convert(3);

                        }
			printf("Press any letter for menu: ");
			scanf(" %c", &anyKey);
                        main();
			break;
                case 4:
                        printf("Enter C for conversion from Celsius to Fahrenheit\n");
                        printf("Enter F for conversion from Fehrenheit to Celsius\n");
                        scanf(" %c", &menuChar);
                        if (menuChar == 'C')
                        {
                                printf("Enter the amount in Celsius to convert to Fahrenheit: ");
                                scanf("%f", &amount);
                                float  convAmount = (amount * 1.8) + 32;
                                printf("%.2f C is %.2f F\n", amount, convAmount);

                        }
                        else if (menuChar == 'F')
                        {
                                printf("Enter the amount in Fahrenheit to convert to Celsius: ");
                                scanf("%f", &amount);
                                float convAmount = (amount -32) / 1.8;
                                printf("%.2f F is %.2f C\n", amount, convAmount);
                        }
                        else {
                                convert(4);

                        }
			printf("Press any letter for menu: ");
			scanf(" %c", &anyKey);
                        main();
			break;
		case 5:
                        exit(0); // exit the program
                default:
                        main(); // display the main menu again, because they entered the wrong number
        }
	
}
