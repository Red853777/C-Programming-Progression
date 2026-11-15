/*Title: Array Data Analyzer
* 
* Purpose: Reads integers from a text file and stores them in a dynamically allocated array. Calculates the average and maximum
*		   values, then displays the results and saves them to an output file.
* 
* Author: Nik Haas
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE* ifp;		// points to the input file so we can read its data
	FILE* ofp;		// points to the output file so we can save our results
	int size;		// Stores how many integers we need to read and allocate memory 
	int sum = 0;
	double average;
	int max;

	//Ensures both input and output filenames were provided
	if (argc != 3)
	{
		printf("Please provide an input and output filename.\n");
		return 1;
	}

	// Opens the file in read mode so we can retrieve the integers
	fopen_s(&ifp, argv[1], "r");

	// Prevents the program from reading a file that fail that failed to open
	if (ifp == NULL)
	{
		printf("File couldn't be opened..\n");
		return 1;
	}
	
	//Prevents the program from using an invalid array size if reading fails
	if (fscanf_s(ifp, "%d", &size) != 1)
	{
		printf("Failed to read array size.\n");
		fclose(ifp);
		return 1;
	}

	if (size <= 0)
	{
		printf("Invalid array size.\n");
		fclose(ifp);
		return 1;
	}

	printf("Array size: %d\n", size);

	// Allocates enough memory to store the integers based on the array size
	int* data = malloc(size * sizeof(int));

	//Prevents the program from accessing memory if allocation fails
	if (data == NULL)
	{
		printf("Memory allocation failed.\n");
		fclose(ifp);
		return 1;
	}
	
	//Ensures all expected integers are successfully read before processing
	for (int i = 0; i < size; i++)
	{
		if (fscanf_s(ifp, "%d", &data[i]) != 1)
		{
			printf("Error reading integer from file.\n");
			free(data);
			fclose(ifp);
			return 1;
		}
	}

	//Displays the stored integers so we can verify they were read correctly
	printf("\nNumbers in the array:\n");
	
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", data[i]);
	}

	// Uses one loop to calculate the sum and find the largest integer
	max = data[0];
	
	for (int i = 0; i < size; i++)
	{
		sum += data[i];

		if (data[i] > max)
		{
			max = data[i];
		}
	}
	
	//Uses double to preserve decimal values during division
	average = (double)sum / size;

	printf("\nAverage: %.2f\n", average);
	printf("Maximum: %d\n", max);

	//Creates an output file to save the calculated results
	fopen_s(&ofp, argv[2], "w");

	//Prevents writing to an invalid file and releases allocated resources 
	if (ofp == NULL)
	{
		printf("Failed to create output file.\n");
		free(data);
		fclose(ifp);
		return 1;
	}

	//Saves the calculated results to a file for later reference
	fprintf(ofp, "Array size: %d\n", size);
	fprintf(ofp, "Maximum: %d\n", max);
	fprintf(ofp, "Average: %.2f\n", average);

	//Releases dynamically allocated memory to prevent memory leaks
	free(data);
	//Closes the input file after processing
	fclose(ifp);
	//closes the output file to ensure all data is saved
	fclose(ofp);

	return 0;
}