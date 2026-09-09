/*Program Name: Basic Enums
* 
* Purpose: To play around with Enumerators and better understand the functionality
* 
* Author: Nik Haas
*/
#include <stdio.h>


enum TrafficLight
{
	Red,		// C makes this = 0
	Yellow,		// C makes this = 1
	Green		// C makes this = 2
};

int main(void)
{
	enum TrafficLight light;

	light = Red;// This stores the enum value that is represented by the name entered in!

	switch (light)
	{
		case 1:
			printf("Red\n\n");
			break;
		
		case 2:
			printf("Yellow\n\n");
			break;
		
		case 3:
			printf("Green\n\n");
			break;

	}
	printf("Enum numerical value: %d\n\n", light);

	return 0;
}