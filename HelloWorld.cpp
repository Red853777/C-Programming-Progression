#include<stdio.h>

int main(void)
{
	char word[50]; // This is the declaration line, char for words, the variable is word with 50 characters 

	printf("What's your name: \n"); // This prompts the users to enter their name

	fgets(word, 50, stdin); // Reads user input (up to 50 characters including spaces), and fgets is for text specifically

	printf("\nYour name is: %s\n\n", word); // This displays the characters the user entered

	return 0;
}