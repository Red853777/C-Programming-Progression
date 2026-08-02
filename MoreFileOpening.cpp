// Project: Opening Files in C, reading strings and numbers, reprints them while doing basic math
// Purpose:
//		- To play with opening files more
//		- Reading more than one line of string
//		- Reading number in
//		- Printing the lines of string
//		- Print the numbers
//		- Do simple math the numbers
//		- Print the math done with the numbers
//
//	Author: Nik Haas
//	Date: 8/2/26

#include <stdio.h>

#define SIZE 41

int main(void)
{
	char name[SIZE];
	char message[SIZE];
	int num1;
	int num2;
	int num3;

	FILE *fp;
	fopen_s(&fp, "", "r");

	if (fp == NULL)
	{
		printf("File not found...\n\n");

		return 1;
	}

	fgets(name, SIZE, fp);			// Reads and saves the top line of words
	fgets(message, SIZE, fp);		// Reads and saves the next line of words
	fscanf_s(fp, "%d %d", &num1, &num2);	// Reads the 2 numbers in the file and saves them
								// Had to be reminded tha fgets is for words, fscanf_s is for numbers
	printf("%s\n", name);
	printf("%s\n", message);
	printf("\n%d %d\n\n", num1, num2);

	num3 = num1 + num2;								// The math done for the 2 numbers takin in
	printf("Here's the 2 numbers added: \n");
	printf("\n%d\n\n", num3);						// The math being printed 

	return 0;
}