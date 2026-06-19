#include <stdio.h>

void SimpleMath(int *ptr1, int *ptr2, int *ptr3, int *ptr4, int *ptr5, double *ptr);

int main(void)
{
	int num1, num2, addResult, subResult,mulResult;
	double divResult;
	int *ptr1, *ptr2, *ptr3, *ptr4, *ptr5;
	double* ptr6;
	ptr1 = &num1;
	ptr2 = &num2;
	ptr3 = &addResult;
	ptr4 = &subResult;
	ptr5 = &mulResult;
	ptr6 = &divResult;

	printf("Enter two numbers: ");

	scanf_s("%d %d", ptr1, ptr2);
	SimpleMath(ptr1, ptr2, ptr3, ptr4, ptr5, ptr6);

	printf("\nHere's some quick math Utilizing pointers\n");
	printf("=========================================\n");
	printf("\nAddition: %d\n", addResult);
	printf("Subtraction: %d\n", subResult);
	printf("Multiplication: %d\n", mulResult);
	if (num2 != 0)
	{
		printf("Division: %.1lf\n\n", divResult);
	}
	else
	{
		printf("Can't divide by 0!\n");
	}
	return 0;
}

void SimpleMath(int *ptr1, int *ptr2, int *ptr3, int *ptr4, int *ptr5, double *ptr6)
{
	*ptr3 = *ptr1 + *ptr2;
	*ptr4 = *ptr1 - *ptr2;
	*ptr5 = *ptr1 * *ptr2;
	*ptr6 = (double)*ptr1 / *ptr2;
}

