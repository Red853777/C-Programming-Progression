#include <stdio.h>

int main(void)
{
	int choice;

	printf("LED Control\n\n");

	printf("1 - Turn LED ON\n");
	printf("2 - Turn LED OFF\n");
	printf("3 - Blink LED\n");

	printf(" \nEnter your choice: ");
	
	scanf_s("%d", &choice);

	switch (choice)
	{
		case 1:
			printf("\nLED ON\n\n");
			break;
		
		case 2:
			printf("\nLED OFF\n\n"); 
			break;

		case 3: 
			printf("\nBLINK LED\n\n");
	}

	return 0;
}