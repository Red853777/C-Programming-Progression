/*
* Program name: Math & Trig Calculator
* 
* Description: This program performs both basic math 
*			   and trig using multiple functions
*
* Features: -User input validation
*			-Loops and if statements
*			-Degree to radian conversion
*			-Formatted tables
* 
* Author: Nik
*/


#include <stdio.h>
#include <math.h>


#define PI 3.14159265

int add(int a, int b)
{
	return a + b;		// Basic addition function
}

int sub(int a, int b)
{
	return a - b;		// Basic subtraction function
}

int mult(int a, int b)
{
	return a * b;		// Basic multiplication funcion
}

double div(int a, int b)
{
	return (double) a / b;	// Basic division function
}

double sine(double degrees)
{
	double radians;
	radians = degrees * (PI / 180);		// Basic sin funtion
	return sin(radians);
}

double cose(double degrees)
{
	double radians;
	radians = degrees * (PI / 180);		// Basic cos function
	return cos(radians);
}

double tangent(double degrees)
{
	double radians;
	radians = degrees * (PI / 180);		// Basic tan function
	return tan(radians);
}

int main(void)
{
	int x, y, sumresult, subresult, multresult;					// variable declarations
	double divresult, angle, sinresult, cosresult, tanresult;
	char choice;
	
	printf("Would you like the program to begin (y/n): ");		// prompts user to start program
	scanf_s("%c", &choice, 1);
	
	while (choice != 'y' && choice != 'Y' && choice != 'N' && choice != 'n')			// Starts the while loop and let's the user know they have to enter the correct characters to start
	{																					// the program otherwise the program will tell them know that it won't start until they do!
		printf("\nYou must type y/n (upper or lower case) to start the program!\n\n");	// Y, y, N, n are the only acceptable characters, especially y and Y.
		printf("Would you like the program to begin (y/n): ");
		scanf_s(" %c", &choice, 1);
	}
	
	if (choice == 'N' || choice == 'n')							// If the user chooses n/N the program will let them know it will just exit
	{
		printf("\nNo problem! Exit the program.\n\n");
	}

	else                                                        // This is where the program actually starts the work after the user enters Y and or y
	{
		printf("\nEnter two numbers: ");
		scanf_s("%d %d", &x, &y);								// Takes in 2 numbers 
		printf("\nAlso enter an angle: ");
		scanf_s("%lf", &angle);									// Takes in an angle

		sumresult = add(x, y);									// Passes the 2 numbers onto each function for the designated math that is to be performed
		subresult = sub(x, y);									//
		multresult = mult(x, y);								//
		divresult = div(x, y);									//

		sinresult = sine(angle);								// Passes the angle to the designated trig function to be performed
		cosresult = cose(angle);								//
		tanresult = tangent(angle);								//

		printf("\n\n=================\n");																	// This is where the table for the basic math is to be printed
		printf("   Simple Math\n");
		printf("=================\n");
		printf("%-5s %-5s %-5s %-5s %-7s %-5s", "x", "y", "Add", "Sub", "Mult", "Div");
		printf("\n------------------------------------\n");
		printf("%-5d %-5d %-5d %-5d %-7d %-5.1lf\n", x, y, sumresult, subresult, multresult, divresult);
		
		printf("\n\n===========================\n");														// This is where the table for trig functions is to be printed
		printf("   Trig Math (in radians)\n");
		printf("===========================\n");
		printf("%-9s %-8s %-8s %-8s", "Angle", "Sin", "Cos", "Tan");
		printf("\n----------------------------------\n");
		printf("%-9.3lf %-8.3lf %-8.3lf %-8.3lf\n\n\n", angle, sinresult, cosresult, tanresult);
	}

	return 0;
}