#include <stdio.h>

int main(void)
{
	const int SPEED = 6;
	int car[SPEED] = { 20, 25, 30, 35, 40, 45 };
	int i;

	printf("Here's the speeds of the cars: \n");

	for (i = 0; i < SPEED; i++)
		printf("%d\n", car[i]);

	return 0;
}