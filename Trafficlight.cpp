/*Title: Traffic Light
* 
* Purpose: To simulate a basic traffic light system using an enum and struct to represent traffic light states
*		   and their corresponding actions. User input is validated before determining whether the driver should
*		   stop, slow down or go.
* 
* Author: Nik Haas
*/

#include <stdio.h>

enum Trafficlight		// This ennum steps up three different numbers as trafficlights and stored as the 
{						// name of Trafficlight
	RED,
	YELLOW,
	GREEN
};

struct ActionsTaken		// This struct stores all of the pieces of related information together into a new data type so
{						// all 3 traffic lights and the actions taken by them get stored here!
	enum Trafficlight light;		// The TrafficLight colors get pulled here and stored as the variable light!
	int Action;		// This stores the action type depending on what which light is present.
};

int main(void)
{
	int choice;		// This variable sets up the what the user will be entering in to choose an action!
	struct ActionsTaken TheAct; // This pulls the list from enum, the items saved in the struct into the main
	TheAct.Action = 0;		// Then .light, .Action both get tied to a color and a number to represent a specifc taken

	printf("What action do you want to choose: \n");	// This promps the user to enter number 0->2 for the colors
	scanf_s("%d", &choice);			// This part takes that number the user enters in

	if (choice >= 3 || choice <= -1)	// This first if statement makes sure the user doesn't enter the wront numbers
	{
		printf("\nThat number won't work try again!\n");
	}
	else
	{
		TheAct.light = (enum Trafficlight)choice;		// You can't set the struct variable name in the main equal
													// to the choice the user makes becuase they're 2 different data
													// types. So, put enum Trafficlight in with the choice variable
													// and put it into () to show that it's being associated with it!

		if (TheAct.light == RED)	// Checks to see if the condition for being RED is true or not
		{
			printf("\nRED means STOP!\n\n");
		}
		else if (TheAct.light == YELLOW)		// Checks to see if the condition for YELLOW is true or not
		{
			printf("\nYELLOW means SLOWDOWN!\n\n");
		}
		else
		{
			printf("\nGREEN means GO!\n\n");	// If neither conditions from above is met, the only condition left is GREEN
		}

	}

	return 0;
}