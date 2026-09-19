/*Title: Dice Roll
* 
*Purpose: To learn how to utilize more preprocessors like time and sttlib which gives access to random number generator
*		  and add them to ones I've already learned.
* 
* Author: Nik Haas
*/
#include <stdio.h>
#include <stdlib.h>
// This part is what allows rand() (random number generator) in the program to work! 
// Standard Library header
#include <time.h>
// This part is what allows time and time manipulation to work in the program
#include <string.h>
// This allows the program to take in strings using fgets
#include <ctype.h>
// This allows individual characters to be worked on for case change
#define SIZE 6

int main(void)
{
	char word [SIZE];
	printf("Press Enter to roll the dice!\n\n");

	fgets(word, SIZE, stdin); // This takes the word/string in from the user

	for (int i = 0; word[i] != '\0'; i++)
	{
		word[i] = tolower(word[i]);
	}

	if (strcmp(word, "enter") == 0) // This if statement is used to make sure that only the word Enter will start 
	{								  // the program 
		printf("Rolling!\n\n");


		clock_t start = clock();						// clock_t is the type like int, float etc. 
														// start is the name of the variable and clock() is the value

		while (clock() < start + 3 * CLOCKS_PER_SEC)
		{
			// The while loop is meant to count 3 seconds before moving forward.
			// The clock is started when the user enters the word Enter to which
			// it counts in seconds with the CLOCKS_PER_SEC and the 3 is the quantity
			// so it counts for 3 seconds before it leaves the while loop 
			// Basically, when the loop starts, it counts each second and checks each
			// second until 3sec or the max is reached, then the loop ends!
		}


		int roll = (rand() % 6) + 1;					// This is the random number generator, it's job is to randomly roll a number
														// and then divide it by 6. After the division, it checks the remainder to see the difference
														// needed to get it from the generated number to the remainder, then adds 1 and prints!
														// For instance, 92 -> 92 / 6 = 15.3, 15 * 6 = 90, 92 - 90 = 2, 2 + 1 = 3, it prints out 3!


		printf("You rolled a %d!\n", roll);
	}
	else
	{
		printf("\nTry again must type Enter!\n\n");
		return 0;
	}
}