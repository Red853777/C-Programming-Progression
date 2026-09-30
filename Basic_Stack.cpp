/*Title: Basic Stack */

/*Purpose: To learn how to write and better understand how to rewrite a stack in a program*/

/*Author: Nik Haas*/

#include <stdio.h>
#define SIZE 5

int main(void)
{
	int stack[SIZE]; // Here is where the stack gets created! It's the array that the stack goes into!
	int top = -1;	// Here is where the stack gets started and where it gets tracked from -1 and increments upwards!

	top++;				// This is where the stacking starts
	stack[top] = 10;	// 10 is the first number that gets added

	top++;				// This is this next addition to be stacked
	stack[top] = 20;	// 20 is the next number that gets added

	top++;				// This is the finall additional stack			  
	stack[top] = 30;	// 30 is the last number to be added to the stack 

	printf("Top Value: %d\n", stack[top]);		// [30] Top 
	printf("Top Index: %d\n\n", top);			// [20]
												// [10] Bottom

	top--;	// Pulls the the top number that has beefrom the stack and should print out the previous number which should be 20!

	printf("Ater pop:\n");
	printf("Top Value: %d\n", stack[top]);
	printf("Top Index: %d\n\n", top);

	top--; // Removes the next number that was on top from the stack. 

	printf("After first pop:\n");
	printf("Top Value: %d\n", stack[top]);
	printf("Top Index: %d\n\n", top);

	return 0;
}