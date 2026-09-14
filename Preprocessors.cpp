/*Preprocessor
* 
* Puropse: To learn how to write and utilize preprocessors 
* 
* Author: Nik Haas
*/

#include <stdio.h>

#define Testing			// This macro activates line 15 & 16 when it's working
						// When // are infront, lines 15 & 16 stop working and lines 19 & 20 start working

//#define Debug -------> This acts as a blocker, when the // are deleted, Debug breaks the
//						 program

#ifdef Testing
#define Message printf("Testing is Good!\n\n")			//This tells the program the program what to print out if it's defined!
#else
#define Message printf("This test works too and is another path!\n\n")	// This print out if line 17 stops being told to print!
#endif

#ifndef Debug
#define DebugMessage printf("Debug has NOT been defined!\n\n")
#endif


int main(void)
{
	Message;			// This is where line 17 is told to print!
	DebugMessage;		// This is where line 19 is told to print!
	return 0;
}

