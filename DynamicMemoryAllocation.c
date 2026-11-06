/*Title: Dynamic Memory Allocation
* 
* Purpose: To demonstrate memory allocation in C using malloc() and calloc() to allocate memory for integers, NULL checks to verify 
*		   successful allocation, and free() to release memory when no longer needed.
* 
* Author: Nik Haas
*/
#include <stdio.h>
// This allow the user to print out the pointers
#include <stdlib.h>
// This allows the use of malloc() and calloc() to be used 

int main(void)
{
	int* ptr, * ptr2;	// This creates 2 pointers
	ptr = malloc(sizeof(int));		// This tells the program to store only the necessary amount of space for the first pointer
									// which is also known as dynamic memory, I've also learn that putting a number infront of the *sizeof
									// part means it'll allocate that specific amount of space for the data that will be provided!
	if (ptr == NULL)	// This if statement checks the ptr to see if the variable can be allocated for storage, if so then the statement
	{					// is ignored and the program continues, if not the program ends hence the return 1
		return 1;
	}

	ptr2 = calloc(1, sizeof(int));	// This tell the program to allocate memory and initiallize it to 0.

	if (ptr2 == NULL)	// This checks to see whether or not calloc failed to allocate memory
	{
		free(ptr);	// This releases the memory allocated by malloc() because calloc() failed
		return 1;
	}

	*ptr = 10;	// This stores the value of 10 into the first pointer

	printf("%d\n", *ptr);	// This is what prints the first pointer or 10
	printf("Calloc Value: %d\n\n", *ptr2);	// This is what prints out the 2nd pointer which has a value of 0 because that's the default for
											// calloc() storage
	free(ptr);	// This frees up the space that was allocated for both pointers now that the program has run its course
	free(ptr2);	// for both pointers

	return 0;
}