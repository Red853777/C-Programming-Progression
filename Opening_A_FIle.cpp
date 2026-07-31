// Project: Opening Files in C
// Purpse: 
//		To learn how to:
//		-Open a text file using fopen_s()
//		-Check whether the file opened successfully
//		-Read a word using fscanf_s()
//		-Print the word to the console
//		-Close the file using fclose() 
//
// Author: Nik Haas
// Date: 7/31/26
//--------------------------------------------------------

#include <stdio.h>
#define SIZE 10						//Array size

int main(void)
{
	char words[SIZE];				//Array name and type
	FILE *fp;						//File pointer for storing the file information
	fopen_s(&fp,"C:\\Users\\nikha\\OneDrive\\Desktop\\C_testing.txt","r");			//Opens the file from location
	
	// Learned I had to use fopen_s with &fp not fp = fopen(....);
	
	if (fp == NULL)									//Tells the program if there's an issue to say there's an issue
	{
		printf("File couldn't be opened...\n\n");
		return 1;
	}

	fscanf_s(fp, "%9s", words, (unsigned)sizeof(words));		//Reads what's in the file

	printf("%s\n\n", words);									//Prints out what's in the file
	fclose(fp);													//Closes the file

	return 0;
}