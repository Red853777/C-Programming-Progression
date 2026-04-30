#include<stdio.h>
#include<math.h>

int main(void) 
{
	double x;
	printf("Enter a number: ");
	scanf_s("%lf", &x);

	printf("\nsin: %.3lf\n", sin(x));
	printf("cos: %.3lf\n", cos(x));
	printf("tan: %.3lf\n\n", tan(x));

	return 0;

}
