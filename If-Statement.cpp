#include<stdio.h>

int main(void)
{
	char y[2];
	printf("If this gets displayed answer with a y or n: \n");
	fgets(y, 2, stdin);

	if (y[0] == 'y')

	{
		printf("\nExcellent it's working\n\n");
	}

	return 0;
}
