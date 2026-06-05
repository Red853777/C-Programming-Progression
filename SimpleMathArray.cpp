#include<stdio.h>

void math(int nump[], int size);

int main(void)
{
	int num[2];
	printf(" Enter two numbers: ");
	scanf_s("%d%d", &num[0], &num[1]);
	math(num, 2);
	
	return 0;
}

void math(int num[], int size)
{
	int add, sub, mult;
	double div;
	add = num[0] + num[1];
	sub = num[0] - num[1];
	mult = num[0] * num[1];
	div =(double) num[0] / num[1];

	printf("\nAddition: %d", add);
	printf("\nSubtraction: %d", sub);
	printf("\nMultiplacation: %d", mult);
	printf("\nDivision: %.1f\n\n", div);
}
