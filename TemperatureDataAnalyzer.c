/*Title: Temperature Data Analyzer
* 
* Purpose: Reads temperature values from an external text file, stores them in an array, displays the recorded temperature, and calculates
*		   their average
* 
* Author: Nik Haas
*/
#include <stdio.h>
// This allows the program to print things

#define MAX_TEMP 20		// This is the preprocessor directive that allows the program create the array capacity to prevent exceeding it 
						// limits

void ReadData(FILE* ptr, int d[], int* size);	// These are the prototypes of the functions before the main so the compiler recognizes them

void PrintData(int d[], int size);

double Average(int d[], int size);

int main(void)
{
	int sz = MAX_TEMP;	// This tracks the number of temperatures read from the file
	FILE *ifp;		// This holds the file pointer needed to access the external file
	int data[MAX_TEMP];		// This reserves space for up to 20 temperature readings

	fopen_s(&ifp, "C:\\Users\\nikha\\OneDrive\\Desktop\\temperatureData.txt", "r");		// This finds and reads the file that the numbers
																						// printed out comes from
	if (ifp == NULL)		// This if statement prints if there's an issue with finding the file
	{
		printf("Failed to open temperatureData.txt\n");
		
		return 1;
	}

	ReadData(ifp, data, &sz);	// This line's job is to read the temperatures from the text file, store them in an array, and update how many
								// temperatures were read
	if (sz == 0)	// This if statement if prints if the program can't find the or doesn't see the numbers that are in the file 
	{
		printf("No temperatures were found.\n");
		fclose(ifp);
		return 1;
	}

	PrintData(data, sz);	// This line's job is to display all temperatures that were successfully ready from the file

	printf("Average Temperature: %.2f F\n\n", Average(data, sz));	// This tell the program to print the text Average Temperature first
																	// then display the calculated average with two decimal places with .2
																	// then print out all the numbers on the line below
	
	fclose(ifp);	// This tells the program to close the opened program after it's opened the temperatureData program and printed what 
					// was on it
	return 0;
}

void ReadData(FILE* ptr, int d[], int* size)	// The function is designed to take the numbers the program finds and reads them all in
{
	*size = 0;		// This resets the counter before reading temperatures from the file

	while (*size < MAX_TEMP && fscanf_s(ptr, "%d", &d[*size]) == 1)		// This reads temperatures while preventing the array from exceeding
	{																	// its capacity
		(*size)++;		// This countes each successfully retrieved temperature
	}
}

void PrintData(int d[], int size)	// This function is designed to print the numbers out
{
	int i;

	for (i = 0; i < size; i++)	// This prints only the temperatures successfully retrieved from the file
	{
		printf("%d ", d[i]);

	}
	printf("\n");
}

double Average(int d[], int size)	// This find the aver	
{
	int i;
	double avg = 0.0;		// This initializes the running total before adding temperatures

	for (i = 0; i < size; i++)	// This adds all recorded temperatures together to calculate their average
	{
		avg += d[i];
	}
	return avg / size;	// This is the final calculation, once the top for loop is done avg contains the sum of all 11 temps
}