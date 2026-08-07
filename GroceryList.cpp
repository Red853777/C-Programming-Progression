/*Grocery list file reader
* 
* Reads the items and their quantities from a text file.
* Stores the quantities in an array and counts the total
* number of entries found in the file
* 
* Author: Nik Haas
* Date: 8/7/26
*/
#include <stdio.h>
#define SIZE 25					// Array size

void TotalAmount(int quantity[], int size);

int main(void)
{
	char item[SIZE];			// Array size for the items
	int quantity[SIZE];			// Array size for the numbers
	int count = 0;
	int result;
	FILE* fp;
	fopen_s(&fp, "C:\\Users\\nikha\\OneDrive\\Desktop\\C_testing.txt", "r");
	
	if (fp == NULL)
	{
		printf("File not found...\n\n");
		return 1;
	}

	while (count < SIZE && (fscanf_s(fp, "%s %d", item, (unsigned)sizeof(item), &quantity[count]) == 2))		// Reads and pulls the items and their quantities and stores them into the item and quantity variables 
	{
		printf("%s %d\n", item, quantity[count]);
		count++;										// Tells the loop to keep counting until there's nothing left to read
	}
	
	TotalAmount(quantity, count);				// Sends the items and quantity info to the bottom function 

	return 0;
}

void TotalAmount(int quantity[], int size)
{
	printf("\nTotal of items in the list: %d\n\n", size);		// Print the total amount of numbers found in the list
}