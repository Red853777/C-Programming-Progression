#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10

enum TrafficLight
{
	Red, 
	Yellow, 
	Green, 
	Invalid
};

int main(void)
{
	enum TrafficLight light = Invalid;
	char string[SIZE];

	printf("Enter one of the three following colors: \n\nRed\nYellow\nGreen\n\n");		// Small list Enums
	fgets(string, SIZE, stdin);						// Where the Enums get accepted when the user types the word

	for (int i = 0; string[i] != '\0'; i++)			// Allow the case change when the user enters a word in.
	{
		string[i] = tolower(string[i]);
	}
	
	if (strcmp(string, "red\n") == 0)				// This compares the case changed word with all 3 words that are
	{												// acceptable and seeing which word it is! 
		light = Red;
	}

	else if(strcmp(string, "yellow\n") == 0)
	{
		light = Yellow;
	}

	else if (strcmp(string, "green\n") == 0)
	{
		light = Green;
	}

	else
	{
		light = Invalid;
	}

	switch (light)						// Switch case prints the number that each word is associated with 
	{
		case Red:
			break;
		
		case Yellow: 
			break;
		
		case Green:
			break;

		case Invalid:															// If the one of the 3 words isn't entered
			printf("You've entered something invalid, try again!\n\n");			// this is what get prints 

	}
	printf("The Enum numerical value you chose was: %d\n\n", light);

	return 0;
}