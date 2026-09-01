#include <stdio.h>
#define SIZE 5

void LargerSmaller(int nums[], int size);
void Incrementing(int nums[], int size);
void Decrementing(int nums[], int size);
void Equals(int nums[], int size);

int main(void)
{
	int nums[SIZE];

	printf("Enter five numbers: ");
	
	for (int i = 0; i < SIZE; i++)
	{
		scanf_s("%d", &nums[i]);
	}

	LargerSmaller(nums, SIZE);

	Incrementing(nums, SIZE);

	Decrementing(nums, SIZE);

	Equals(nums, SIZE);

	return 0;
}

void LargerSmaller(int nums[], int size)
{
	int largest = nums[0];						// declare the variable largest as nums first number
	
	for (int i = 1; i < size; i++)								// the for loop takes in all 5 numbers and puts them through a if statement
	{
		if (nums[i - 1] > nums[i])				// This condition tells the if statement to find the largest number by comparing each one after the last
		{
			printf("Comparing %d > %d\n", nums[i - 1], nums[i]);		// This prints out the largest number once it has been found
			largest = nums[i];				// This saves the largest number as the largest variable
		}
		else 
		{
			printf("Comparing %d > %d\n", nums[i], nums[i - 1]);
		}

		if (nums[i] > largest)
		{
			largest = nums[i];
		}
	
	}
	printf("\nThe largest number is: %d\n", largest);

}

void Incrementing(int nums[], int size)
{
	int pass;
	
	for (int move = 0; move < size - 1; move++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				pass = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = pass;
			}
		}
	}

	printf("\nHere's your the numbers you entered in incrementing order:\n");

	for (int i = 0; i < SIZE; i++)
	{
		printf("% d", nums[i]);
	}
	printf("\n\n");
}

void Decrementing(int nums[], int size)
{
	int pass1;

	for (int move = 0; move < size - 1; move++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (nums[i] < nums[i + 1])
			{
				pass1 = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = pass1;
			}
		}
	}

	printf("\nHere's the numbers you entered in decrementing order:\n");

	for (int i = 0; i < SIZE; i++)
	{
		printf("% d", nums[i]);
	}
	printf("\n\n");
}

void Equals(int nums[], int size)			// This function checks the five numbers to see if there are 2 that are
{											// the same.
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (nums[i] == nums[j])			// This is what checks if they are the same or not
			{
				printf("These numbers are the same: %d %d\n\n", nums[i], nums[j]);
			}
		}
	}
}


