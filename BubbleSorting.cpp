#include <stdio.h>
#define SIZE 5

void BubbleSortAscending(int nums[], int size);			// declaring the incrementing sorting below

void BubbleSortDescending(int nums[], int size);		// declaring the decrementing sorting below

int main(void)
{
	int nums[SIZE];									// array called num with the size quantity of 5
	printf("Enter 5 numbers: ");

	for (int i = 0 ; i < SIZE; i++)
	{
		scanf_s("%d", &nums[i]);					// the array accepting 5 random number from the user
	}
	
	BubbleSortAscending(nums, SIZE);							// the array being sent to the bottom function
	printf("Here's the numbers you entered from smallest to largest: \n\n");

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", nums[i]);						// the function printing off the new arrangement of the array
	}												// from the smallest number to the largest number
	printf("\n\n");

	BubbleSortDescending(nums, SIZE);
	printf("Here's the numbers you entered from largest to smallest: \n\n");

	for (int i = 0; i < SIZE; i++)					// the function printing off the new arrangement of the array 
	{												// only it's largest to smallest unlike the for loop above
		printf("%d ", nums[i]);
	}

	printf("\n\n");
	return 0;
}

void BubbleSortAscending(int nums[], int size) 
{
	int temp;
	for (int pass = 0; pass < size - 1; pass++)		// the first for loop counting how many times it has to count
	{
		for (int i = 0; i < size - 1; i++)			// the 2nd for loop that looks at the number attached to the count
		{
			if (nums[i] > nums[i + 1])				// this is where the numbers get compared 
			{
				temp = nums[i];						//
				nums[i] = nums[i + 1];				// here's where the numbers get rearranged and saved in their new positions
				nums[i + 1] = temp;					//
			}
		}
	}
}

void BubbleSortDescending(int nums[], int size)		// I found this whole thing to be nearly identical to the 
{													// ascending order, the exception is the inner if statement!
	int temp1;										// the < sign is opening towards the larger number not smaller
	for (int pass = 0; pass < size - 1; pass++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (nums[i] < nums[i + 1])
			{
				temp1 = nums[i];			
				nums[i] = nums[i + 1];
				nums[i + 1] = temp1;
			}
		}
	}
}