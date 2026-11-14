/*Title: Simple File Copier
* 
* Purpose: Reads text from an input file, copies it into a separate output file with double spaceing, and displays the results in the
*		   console. Uses comman-line arguments to specify the input and output files.
* 
* Author: Nik Haas
*/
#include <stdio.h>
// This allows the program to utilize printf, fopen_s, getc, putc, rewind, and fclose


int main(int argc, char* argv[])
{
	FILE* ifp;		// Hold the input file pointer
	FILE* ofp;		// Holds the output file pointer
	int c;
	
	if (argc != 3)		// This ensures both filenames were provided before opening files
	{
		printf("Please provide an input and output filename.\n");
		return 1;
	}

	fopen_s(&ifp, argv[1], "r");	// This uses command-line arguments to avoid hardcoding file locations

	if (ifp == NULL)	// This prevents reading from a file that failed to open
	{
		printf("Failed to open input file.\n");
		return 1;
	}

	fopen_s(&ofp, argv[2], "w+");	// This creates a separate file to preserve the original text

	if (ofp == NULL)		// This prevents writing to a file that failed to open
	{
		printf("Failed to open output file.\n");
		fclose(ifp);
		return 1;
	}

	while ((c = getc(ifp)) != EOF)		// This copies the characters until the original file reaches its end
	{
		putc(c, ofp);

		if (c == '\n')		// This inserts an extra newline to double-space the text
		{
			putc('\n', ofp);
		}
	}

	rewind(ofp);	// This returns to the beginning so the copied text can be displayed 

	while ((c = getc(ofp)) != EOF)		// The reads the copied file to display its contents in the console
	{
		putc(c, stdout);
	}

	printf("\n\n");		// This separates the program's output from Visual Studios's debugger messages

	fclose(ifp);		// These release file resources after processing is complete
	fclose(ofp);

	return 0;
}