#include<stdio.h>

int main(void)
{
	int x, y, sum, sub, mult; // declares whole number variables
	double div; // Declares the only decimal number

	printf("Enter 2 numbers and watch some math happen: "); // Prompts user to enter 2 numbers
	scanf_s("%d %d", &x, &y); // stores the numbers as int

	sum = x + y; // Here's the simple math for both int's
	sub = x - y;
	mult = x * y;
	div = (double)x / y; // Converts the 2 ints into a double to give an accurate answer

	printf("\nSum: %d\n", sum);		//
	printf("Sub: %d\n", sub);		// Displays each answer  
	printf("Mult: %d\n", mult);	//
	printf("Div: %.1lf\n\n", div);	// The last answer prints to 1 dec place

	return 0;
}