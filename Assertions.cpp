/*Title: Assertions
* 
*Purpose: To see how assertions work and how they get setup.
* 
* Author: Nik Haas
*/
#define NDEBUG				// NDEBUG is meant to bypass the assertion, the program runs so long as it's
#include <assert.h>			// defined. But, it must be defined BEFORE the assertion is included!
// This allows the assertion tool to be used in the program!
#include <stdio.h>
// This allows the program to utilize printf so that line 16 can be displayed!

int main()
{
	assert(0);
	printf("This program should work just fine!\n\n");		// This prints out so long as NDEBUG is defined!

	return 0;		// If NDEBUG is not defined it breaks the program and asks if you want to abort.
}