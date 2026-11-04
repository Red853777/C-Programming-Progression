/* Title:  Additional Advanced I/O's
* 
* Purpose: Demonstrates advanced printf() formatting techniques, including decimal precision, scientific notation, number alignment, 
*		   zero padding, hexidecimal, octal, memory address, and string formatting
* 
* Author: Nik Haas
*/
#include <stdio.h>

int main(void)
{
	double number;
	unsigned int integerNumber;
	char word[] = "Embedded";

	printf("Enter a decimal numer: ");
	scanf_s("%lf", &number);			// This part allows the program to store any decimal to be stored in the program
	integerNumber = (unsigned int)number;	// This part allows the program to convert the decimal number into an unsigned integer


	//Regular Formatting
	printf("Standard Format: %f\n", number);
	printf("Scientific Notation: %e\n", number);
	printf("Three Decimal Places: %.3f\n\n\n", number);

	//Advanced Formatting
	printf("Zero padding: %05u\n", integerNumber);	// %05u is meant to be used with unsigned numbers, the 05 is meant to tell the program 
													// to fill the space with 5 digit using 0 where necessary to make the 5 digits.
	printf("Sign display: %+.3f\n", number); // This displays the inter digit the user enters, just with a shows it as a positive number
	printf("Sign display: %.3f\n", -number); // This does the same as the line above, just with the negative version
	printf("Hexidecimal: %x\n", integerNumber); // This displays a hexadecimal 
	printf("Prefix Hexidecimal: %#x\n", integerNumber);  // This adds the 0x part to the hexadecimal print out
	printf("Octal: %o\n", integerNumber);	// This diplays the number in an Octal (base 8)
	printf("Memory address: %p\n", (void*)&number);	// This telling the program to print out the memory or address of the number 
													// or in this case some random number that has nothing to do with the number
													// that was entered.
	printf("String Formatting : |%15s|\n", word);	// This print out a word but pushes it 15 spaces to the right

	return 0;
}