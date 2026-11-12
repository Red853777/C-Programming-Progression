/*Title: List of 50
* 
* Purpose: To create a program that utilizes the linked list by creating multiple functions that make the list through a for loop, allocate 
*		   the memory dynamically through malloc and release the memory after the numbers have been printed and are no longer needed
* 
* Author: Nik Haas
*/
#include <stdio.h>
// This allows for things to be printed in the program
#include <stdlib.h>
// This allows functions like dynamic memory allocation and random number generation to be useable

struct Numbers
{
	int data;
	struct Numbers* next;
};

struct Numbers* Start(void);	// This creates a prototype declares a function that returns a structure pointer, it declares a function	
								// mamed Start that will return a pointer to a Numbers structure

void PrintList(struct Numbers* head);	// This creates a prototype for the function that will print all the numbers in their stored address

void Freelist(struct Numbers* head);	// This creates a prototype for 

int main(void)
{
	struct Numbers* List = Start();	// This calls Start() to create the Linked List and stores the address of its first node in the list

	if (List == NULL)
	{
		printf("Failed to creat the Linked List...\n");
		return 1;
	}

	PrintList(List);

	return 0;
}

struct Numbers* Start(void)		// This structure is what actually makes the list of 50 numbers
{
	struct Numbers* head = NULL;	// This pointer allows the program to remember the address of the first node (number) in the list is.
	struct Numbers* nextNumber = NULL;	// This pointer holds the address of the new node being created 
	struct Numbers* tail = NULL;	// This pointer tracks the last node so new nodes can be connected to the end of the list

	for (int i = 0; i < 50; i++)
	{
		nextNumber = malloc(sizeof(struct Numbers));	// This is what allocates the memory for the node be added to the list
		
		if (nextNumber == NULL)	// This checks to see if the allocations has failed to prevent the program from using invalid memory
		{
			Freelist(head);		// This gets rid of previously allocated nodes to prevent memory leaks if any allocation failure  
			return NULL;	// This let the main function know that the linked list was not able to be made
		}

		nextNumber->next = NULL;	// This initializes the pointer so it doesn't have an unknown memory address, and makes sure that the new
									// node isn't connected to another node just yet
		
		nextNumber->data = i + 1;	// This shifts the numbers over by adding 1 to the first integer rather than starting with 0
		
		if (head == NULL)		// This if statement checks if the list is empty so the first node can be established
		{
			head = nextNumber;		// This save the first node's address so the beginning of the list isn't lost
			tail = nextNumber;		// This establishes the first node as the end of the list until more nodes are added
		}
		else					// This handles adding new nodes once the first node has been established
		{
			tail->next = nextNumber;	// This connects the last node to the newly created node
			tail = nextNumber;			// This updates the end of the list so additional nodes can be connected
		}
	}
	
	return head;	// This makes sure that the address of the first node is returned to main so that main can access the rest of the list
}

void PrintList(struct Numbers* head)	// This function is what allow the program to both print all the numbers and print them in a specific
{										// way (rows of 5 rows of 10
	struct Numbers* current = head;
	int count = 0;
	
	while (current != NULL)		// This while loop starts prints the list so long as there's list to be printed 
	{
		printf("%3d ", current->data);	// Here's where the printing part takes place and 3 makes the program print out more evenly

		count++;	// This tracks how many numbers have printed to determine when a new row is needed

		if (count % 10 == 0)	// This tell the program to print the each number in a rows of 10 
		{
			printf("\n");	// This tell the program to go to the next line when a row of 10 numbers is reached
		}
		current = current->next;	// This tells the program to continue looking through the list
	}
	printf("\n\n");		// This is what creates the space between the last row of the list and the bottom printed files that get displayed
}

void Freelist(struct Numbers* head)		// This function is what releases the dynamic allocated memory holding the the nodes made from 
{										// PrintList
	
	struct Numbers* current = head;		// This starts at the first node so each node can be accessed and freed

	while (current != NULL)		// This while loop is meant to continue until every node in the list has been freed
	{
		struct Numbers* nextNumber = current->next;		// This saves the next node's address before the current node is freed
		
		free(current);		// This releases the memory allocated for the current node
		
		current = nextNumber;		// This moves to the saved node so the remaining nodes can be freed
	}
}