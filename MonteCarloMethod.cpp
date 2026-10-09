/*Title: Monte Carlo Method
* 
* Purpose: To emulate the Monte Carlo method of using 1 million seven-card poker hands to approximate the probabilities
*		   of different poker hand types through Enums, Struct, If-else statements, for loops, arrays and function
*		   manipulation.
* 
* Authoer: Nik H.
*/
#include <stdio.h>
// Allows the program to print things out and calculate probabilities to the console!
#include <stdlib.h>
// Allows the program to utilize rand() for generating pseudorandom numbers & srand() to initailizing the 
// random number generator
#include <time.h>
// Allows for time manipulation for random number generator (NULL)!

enum Suits	// This creates the list of all 4 suits in the deck
{
	Clubs,
	Diamonds, 
	Hearts, 
	Spades
};

struct Card		// Groups the suit and rank together so each Card represents one complete playing card! 
{
	enum Suits suit;	
	short rank;			
};

void shuffleDeck(struct Card deck[]); // Declares shuffleDeck before main so it can be called befored its full definition appears

int main(void)
{
	struct Card deck[52];	// Stores the complete deck so all 52 cards can be built and shuffled
	struct Card hand[7];		// Stores the 7 cards being evaluated during each Mont Carlo tral
	int index = 0;			// The index tracks the next available position while building all 52 cards in the deck array
	
	int noPairCount = 0;		// each of these variables stores the totals of how many of the million hands fall into each category
	int onePairCount = 0;
	int twoPairCount = 0;
	int threeKindCount = 0;
	int fullHouseCount = 0;
	int fourKindCount = 0;

	srand((unsigned int)time(NULL));	// Uses the current time as a seed so the deck can be shuffled differently each time the program runs

	for (int suit = 0; suit < 4; suit++)	// This loop handles the for suits
	{
		for (int rank = 1; rank <= 13; rank++)	// This loop handles the 13 ranks (#'s) for each suit!
		{
			deck[index].suit = (enum Suits)suit;	// This combines each of the 4 suits with all 13 ranks to build every card in the 52 card deck
			deck[index].rank = rank;				//
			index++;								// This part is the heart of the Monte Carlo part!
		}											//
	}

	for (int trial = 0; trial < 1000000; trial++)	// Repeats the random 7-card experiment 1million times so the hand probabilities can be approximated
	{
		shuffleDeck(deck);	// The shuffling begins here!

		for (int i = 0; i < 7; i++)		// This loops acts as the dealing part by creating what the users 7 card in-hands would be 
		{
			hand[i] = deck[i];
		}

		int rankCount[14] = { 0 };	// The score board for the 13 possible card ranks

		for (int i = 0; i < 7; i++)		// This loop keeps track of what ranks are in each hand each time the user gets dealt a hand
		{
			rankCount[hand[i].rank]++;
		}

		int pairs = 0;		//
		int threes = 0;		// Keeps track of repeated ranks in the current hand so its poker hand type can be determined
		int fours = 0;		//

		for (int rank = 1; rank <= 13; rank++)		// This loops job is to count each time each rank shows up as a repeated rank and stores that
		{											// information
			if (rankCount[rank] == 2)
			{
				pairs++;
			}
			else if (rankCount[rank] == 3)
			{
				threes++;
			}
			else if (rankCount[rank] == 4)
			{
				fours++;
			}
		}

		if (fours >= 1)		// This if-else statement is meant to count how many times each repeated classification type happens and record it 
		{
			fourKindCount++;
		}
		else if (threes >= 1 && (pairs >= 1 || threes >= 2))
		{
			fullHouseCount++;
		}
		else if (threes >= 1)
		{
			threeKindCount++;
		}
		else if (pairs >= 2)
		{
			twoPairCount++;
		}
		else if (pairs == 1)
		{
			onePairCount++;
		}
		else
		{
			noPairCount++;
		}

	}
	
	printf("No Pair: %f\n", (double)noPairCount / 1000000);		// Divides each hand total by the 1million trails to calculate and display
	printf("One Pair: %f\n", (double)onePairCount / 1000000);	// the estimated probabilities
	printf("Two Pair: %f\n", (double)twoPairCount / 1000000);
	printf("Three of a Kind: %f\n", (double)threeKindCount / 1000000);
	printf("Full House: %f\n", (double)fullHouseCount / 1000000);
	printf("Four of a Kind: %f\n", (double)fourKindCount / 1000000);
	
	return 0;
}

void shuffleDeck(struct Card deck[])	// This 2nd function is what does the actual shuffling, and it's meant to work backwards	
{
	for (int i = 51; i > 0; i--)
	{
		int j = rand() % (i + 1);
		
		struct Card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;

	}
}