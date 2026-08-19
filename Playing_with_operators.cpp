/*	Program name: Playing With Operators
*	
*	Purpose: To play around with < and > operators
*	
*	Author: Nik Haas
*/

#include <stdio.h>
#define SIZE 2

void Operators(int nums[], int size);			// Declared Operator Function

int main(void)
{
	int nums[SIZE];

	printf("Enter 2 numbers: ");
	
	for (int i = 0; i < SIZE; i++)
	{
		scanf_s("%d", &nums[i]);
	}
	
	Operators(nums, SIZE);
		
		return 0;
}

void Operators(int nums[], int size)				// Operator Function that uses simple if-else statements 
{													// to compare to numbers and tells which is larger and smaller

	if (nums[0] > nums[1])
	{
		printf("\nThis number is larger: %d\n", nums[0]);
		printf("\nThis number is smaller: %d\n", nums[1]);
	}

	else if (nums[0] < nums[1])
	{
		printf("\nThis number is larger: %d\n", nums[1]);
		printf("\nThis number is smaller: %d\n", nums[0]);
	}

}