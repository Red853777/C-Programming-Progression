#include <stdio.h>
// The allow the program to print 

struct Numbers		// This creates the Numbers struct that holds data and next for storing the numbers and telling the program to move
{					// incrementally when when storing the numbers
	int data;
	struct Numbers* next;
};

void PrintNumbers(struct Numbers* start);

int main(void)
{
	struct Numbers First;	// These pull the struct Numbers into the main function, then create the different named numerical variables
	struct Numbers Second;
	struct Numbers Third;
	struct Numbers Fourth;
	struct Numbers Fifth;

	First.data = 5;			// Each line with .data connects the worded number to the actual number 
	First.next = &Second;	// Each line with .next connects the previous number to the next one in the link

	Second.data = 10;
	Second.next = &Third;

	Third.data = 15;
	Third.next = &Fourth;

	Fourth.data = 20;
	Fourth.next = &Fifth;

	Fifth.data = 25;
	Fifth.next = NULL;	// This tell the program that there's nothing more being added after the fifth number 

	struct Numbers* current = &First;	// This connects the variable current the first number

	PrintNumbers(current);
	
	return 0;
}

void PrintNumbers(struct Numbers* start)
{
	while (start != NULL)	// This starts the condition of the while loop, by checking to make sure that there's a list made
	{
		printf("%d ", start->data);		// After verifying that the list is made, it starts to print the list from start which is connected
										// to data which starts at 5
		start = start->next;		//
	}
	printf("\n");	// This creates a one line of spacing between what's being printed and the stuff below. If it's put in the while loop
}					// it mmakes the program print the numbers top to bottom rather than left to right. I wanted them to print out left to 
					// right 