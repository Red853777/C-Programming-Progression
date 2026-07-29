/*
* Program: Merge Sort
* Author: Nik
* Purpse: 
*	To read 6 integer from the user and sort them using Merge Sort Algorithm
* 
* Concepts Practiced:
*	- Functions
*	- Recursions
*	- Arrays
*	- Temporary arrays
*	- Divide and Conquer
*/
#include <stdio.h>
#define SIZE 6

void MergeSort(int nums[], int left, int right);
void Merge(int nums[], int left, int middle, int right);

int main(void)								// Main function for taking 6 numbers in as an array through a for loop
{											// and displays those 6 numbers in from smallest to largest
	int nums[SIZE];

	printf("Enter 6 numbers:\n");

	for (int i = 0; i < SIZE; i++)
	{
		scanf_s("%d", &nums[i]);
	}

	MergeSort(nums,0, SIZE - 1);			// This forces the program to shift the index reading over 1 to the left
											// nums: array size/ 0: starting point/ SIZE - 1: Ending point ( 6 - 1 = 5)
	printf("\nNumbers Entered:\n");

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d", nums[i]);
	}

	printf("\n");
}

void MergeSort(int nums[], int left, int right)			// This function breaks the numbers into 2 different arrays 
{														// Then calls Merge() to sort and recombine them
	if (left < right)
	{
		int middle = (left + right) / 2;
		
		MergeSort(nums, left, middle);
		MergeSort(nums, middle + 1, right);
		Merge(nums, left, middle, right);
	}
	
}

void Merge(int nums[], int left, int middle, int right)		// This function combines the 2 arrays back into one
{															// by comparing the numbers and setting up smallest
	int i = left, j = middle + 1, k = left;					// to largest and sends the newly arranged array back
	int temp[SIZE];											// to the main function

	while (i <= middle && j <= right)
	{
		if (nums[i] < nums[j])
		{
			temp[k++] = nums[i++];
		}
		else
		{
			temp[k++] = nums[j++];
		}
	}

	while (i <= middle)
	{
		temp[k++] = nums[i++];
	}

	while (j <= right)
	{
		temp[k++] = nums[j++];
	}

	for (i = left; i <= right; i++)
	{
		nums[i] = temp[i];
	}
}