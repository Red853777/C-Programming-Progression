#include <stdio.h>

void math(int num[], int result[], double *div, int size); // double *div is the pointer part

int main(void)
{
	int num[2], result[3];
	double div;
	printf("Enter two numbers: ");
	scanf_s("%d%d", &num[0], &num[1]);
	math(num, result, &div, 2);					// &div is now a pointer
	printf("\nAddition: %d", result[0]);
	printf("\nSubraction: %d", result[1]);
	printf("\nMultiplication: %d", result[2]);
	printf("\nDivision: %.1lf\n\n", div);
}

void math(int num[], int result[], double *div, int size)
{
	int add, sub, mult;
	
	add = num[0] + num[1];
	sub = num[0] - num[1];
	mult = num[0] * num[1];
	
	*div = (double)num[0] / num[1];				// the pointer is still apart of the math just on its own!					
	result[0] = add;
	result[1] = sub;
	result[2] = mult;

}