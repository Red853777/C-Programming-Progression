#include<stdio.h>

int main(void)
{
	int x, z, sum, sub, mult;
	double div;
	char y[2];

	printf("Do you want to see some math happen (y/n): ");
	fgets(y, 2, stdin);

	if (y[0] == 'y' || y[0] == 'Y')
	{
		printf("\nEnter 2 numbers: ");
		scanf_s("\n%d %d", &x, &z);

		sum = x + z;
		sub = x - z;
		mult = x * z;


		printf("\nSum: %d\n", sum);
		printf("Sub: %d\n", sub);
		printf("Mult: %d\n", mult);


		if (x == 0 || z == 0)
		{
			printf("\nThe division is undefined...\n\n");
		}
		else
		{
			div = (double)x / z;
			printf("Div: %.1lf\n", div);
		}

	}
	else
	{
		return 0;
	}

}