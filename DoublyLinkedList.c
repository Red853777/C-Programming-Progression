/*Title: Doubly Linked List
* 
* Purpose: Generates 200 random integers between 0 and 49, stores them in a doubly linked list, sorts them in ascending order using
*		   bubble sort, and removes duplicate values so each integer appears only once.
* 
* Author: Nik Haas
*/
#include <stdio.h>
//This allow the program to print everything
#include <stdlib.h>
//This provides functions for dynamic memory allocation and random number genration
#include <time.h>
//This provides current time to seed the random number generator

struct Node		// This defines each node's data and its connection to the next node in the linked list
{
	int data;	// This member stores the integer associated with each node
	
	struct Node *next;	// This declares a pointer that can hold the memory address of another struct node
	
	struct Node* prev;	// This declares a pointer that holds the memory address for the previous node, allowing backward traversal through
						// the doubly linked list
};

struct Node *CreatedList(void);		// This are the declared functions for the program!

void FreeList(struct Node* head);

void PrintList(struct Node* head);

void BubbleSort(struct Node* head);

void RemoveDuplicate(struct Node* head);

int main(void)
{
	srand((unsigned int)time(NULL));	// This initiallizes the random number generated using the current time, it's only needed once  

	struct Node* head = CreatedList();	// This calls CreateList which creates the 100 connected nodes and stores the address of the 
										// first node in a pointer named head
	if (head == NULL)	// This if statement checks whether CreatedList() has successfully created the linked list, if not it prints 
	{					// out what's inside 
		printf("Failed to create linked list.\n");
		return 1;
	}

	BubbleSort(head);	// This allows the program to be display the sorted integers in rows of five
	
	RemoveDuplicate(head);	// This removes repeated values while preserving the doubly linked list connections
	
	PrintList(head);	// This allows the program to display the sorted integers in rows of five
	
	FreeList(head);		// Thes allows the release of the allocated memory after the list is no longer needed
	

	return 0;
}

struct Node *CreatedList(void)	// This functions creats the list of 100 numnbers
{
	struct Node *head = NULL;	// The list is empty, there's is nothing in it yet
	struct Node *newNode = NULL;	// This allows the program to contain an unpredictable address before it's assigned a valid one
	struct Node *tail = NULL;	// This tracks the last node so new nodes can be connected to the end of of the list

	for (int i = 0; i < 200; i++)	// The repeats the process 200 times to create and connect each node in the linked list
	{
		newNode = malloc(sizeof(struct Node));	// This allocates enough memory for one complete node so it can be added to the 
												// linked list
		if (newNode == NULL)	// This checks for allocation failure to prevent the program from accessing invalid memory
		{
			FreeList(head);	// This releases previoulsy allocated nodes to prevent memory leaks if allocation fails
			return NULL;	// This signals to main() that the linked list could not be created successfully
		}

		newNode -> data = rand() % 50;	// This generates a pseudorandom integers between 0 and 49
		
		newNode -> next = NULL;	// This initializes the node's pointer to NULL because we haven't connected it to another node yet
		
		newNode -> prev = NULL; //This initializes the previous pointer because the new node is not connected to another node yet

		if (head == NULL)	// This determines whether it's adding the first node or connecting another node to the existing linked list
							// it also only executes during the first iteration, otherwise the head is no longer NULL
		{
			head = newNode;	// These show that both head and tails are assigned an address, and a starting point is created
			tail = newNode;
		}
		else    // This is where the work happens, the else statement connects each new node to the end of list
		{
			tail -> next = newNode;	// This is where the new node's address inside the previous last node's next member
			
			newNode -> prev = tail;	// This connects the new node to the previous last node, allowing backward traversal
			
			tail = newNode;		// This updates tail so it points to the new node that was just added
		}
	}

	return head;
}

void FreeList(struct Node* head)	// This function is created to release the memory that was allocated for the nodes in the linked list
{
	struct Node *current = head;	// Declares a pointer that initially holds the same address as head, allowing the program to traverse
									// the linked list
	while (current != NULL)	// This means the while loop will run so long as current insn't empty
	{
		struct Node *nextNode = current->next;	// This saves the address of the next node
		
		free(current);	// This releases the memory allocated for the node that current points to
		
		current = nextNode;	// This updates current to point to the next node in the linked list
	}
}

void PrintList(struct Node* head)	// This prints the createdlist 
{
	struct Node* current = head;	// This creates a pointer that starts at the beginning of the linked list
	int count = 0;	// This creates a variable that will keep track of how many integers that have been printed 

	while (current != NULL)	// This is meant to keep the program moving through the linked list until it reaches the end
	{
		printf("%d ", current->data);	// This prints the integer stored in the code that current is pointing to
		
		count++;	// This increases the value of count by 1 each time an integer is printed

		if (count % 5 == 0)	// This checks whether five integers have been printed so the program knows when to start a new row
		{
			printf("\n");
		}
		current = current->next;	// This moves current to the next node in our linked list
	}
	printf("\n\n");
}

void BubbleSort(struct Node* head)	// This sorts the integers in the linked list into ascending order utilizing the bubble sort
{
	struct Node *current;	// This pointer allows the information to travel through the linked list, comparing the integers stored in 
							// neighboring nodes
	struct Node *lastSwap = NULL;
	struct Node *end = NULL;
	int temp;	// Temp is created to temporarily hold an integer while swapping two values
	int swapped = 0;	// This variable will help to determine whether any values were exchanged during a pass through the linked list

	do	// Begins a sorting pass that will repeat if any values are swapped
	{
		swapped = 0;	// This resets the swap indicator before each pass to check whether addtional sorting is needed
		current = head;	// This makes the program return to the beginning fo the linked list for each sorting pass

		while (current != NULL && current->next != end)	// This continues comparing neighboring nodes until the end of the list
		{													// is reached
			if (current->data > current->next->data)	// This asks whether the current node contains a larger integer than the next node
			{
				// These lines are what are the heart of the bubble sort, they are responsible for 
				// swapping the integers stored in two neighbors nodes
				temp = current->data;				//This stores the original value
				current->data = current->next->data;//This takes the value from the next node and stores it in the current node
				current->next->data = temp;			//This takes the saved value and places it in the next node

				swapped = 1;	// This tells the program that at least one swap occured during the current pass through the linked list
			}

			current = current->next;	// This advances to the next node so each neighboring pair can be compared
		}
	} while (swapped != 0); // This repeats the sorting process until an entire pass finishes without any swaps
}

void RemoveDuplicate(struct Node* head)
{
	struct Node* current = head;
	
	while (current != NULL && current->next != NULL)
	{
		if (current->data == current->next->data)
		{
			struct Node* duplicate = current->next;

			current->next = duplicate->next;

			if (duplicate->next != NULL)
			{
				duplicate->next->prev = current;
			}
			
			free(duplicate);
		}
		else
		{
			current = current->next;
		}
	}
}