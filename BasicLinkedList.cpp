/*Title: Basic Linked List
* 
* Purpose: To understand how linked list work by creating multiple structs that store integers and connecting them using pointers.
*		   The program uses a while loop to traverse the linked list, access the stored integers, and print them until the end of the list 
*		   is reached.
* 
* Author: Nik Haas
*/
#include <stdio.h>
// This allows the program to print everything out!

struct String		// This struct sets up the variables and pointers under the name of String
{
	int data;
	struct String* next;
};

int main()
{
	struct String First;		// Variable name created named First
	struct String Second;		// Variable name created named Second
	struct String Third;		// Variable name created named Third


	First.data = 1;			// first is now associated with data from the structure
	First.next = &Second;	// first is also associated with next which is a pointer from the structure, when it's set equal to NULL
							// that means it's not connected and won't go further. If it's connected to the next variable that's associated
							// with the struct then the list will begin until one is set equal to NULL.

	Second.data = 3;		// Second is now associated with data from the structure
	Second.next = &Third;	// Second is also associated with next which is a pointer from the structure that points to the variable named
							// Third

	Third.data = 5;			// Third is now associated with data from the structure
	Third.next = NULL;		// Here is where the list ends with Third.next = NULL. 

	struct String* current = &First;	// This line is made to connect the new variable name current with the struct String pointer 
										// and have it look at the variable First right off the bat!

	while (current != NULL)		// This while loop is made to allow all 3 numbers in the stored in data to print all at once by telling it
	{							// to start with current and print everything until it reaches a the Thrid variable, sees next and then sees
								// NULL. At that point it'll stop. 
		printf("%d,  ", current->data);
		current = current->next;		// This tells the program to print out the current that's connected to data, then keep going with next!
	}


	return 0;
}