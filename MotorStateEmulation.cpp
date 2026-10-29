/*Title: Motor Emulator
* 
* Purpose: To understand how a program can simulate motor operations through user input. The program provides a menu that allows the user 
*		   to turn the motor ON, select clockwise rotation, adjust its speed between 5% and 100%, and control operating state, including 
*		   pulsing and stopping. The user can also exit the program through the menu.
*
* Author: Nik Haas
*/
#include <stdio.h>

enum MotorCommands		// This sets up the commands for the motor, whether the user wants to program to start
{						// the motor, tell it to pulse, stop the motor or end the program itself!
	START,
	PULSE, 
	STOP, 
	SET_CLOCKWISE,
	SET_COUNTERCLOCKWISE,
	SET_LOW_SPEED,
	SET_FULL_SPEED,
	EXIT
};

enum MotorStatus		// This sets up the status of the emulated motor to let the user know if the motor is
{						// still running or not.
	RUNNING,
	PULSING,
	STOPPED
};

enum MotorDirection		// This sets up the direction of travel (Forward & Reverse)
{
	NO_DIRECTION,
	CLOCKWISE,
	COUNTERCLOCKWISE
};

struct Motor				// This combines the status of the motor with it's speed 
{
	enum MotorStatus status;
	enum MotorDirection Direction;
	int speed;
	int powerOn;
};

int main(void)
{
	struct Motor Motor1;	// This part bring the struct and it's variables into the main functiona give it 
							// a specific name to be used in the main function.
	
	Motor1.status = STOPPED;	// This variable has been initialized as an enum so a word has to be used for the 
								// setup
	Motor1.Direction = NO_DIRECTION;	// This connects the the variable Motor1 from the struct in main with the Direction 
										// variable to utilize througout the program
	
	Motor1.speed = 0;		// This is variable in the struct is a regular variable (int) so a number can be used  	
							// for the setup
	
	Motor1.powerOn = 0;		// This ensures the motor starts powered OFF until the user selects START

	enum MotorCommands MotorState;	// This allows the main to communicate with the enum and state the enum as 
									// as a variable and name it Motorstate!
	int choice = 1;	// This initialization is important because this is what goes through the while loop 
					// first! 
	
	printf("===================================\n");	// This prints out out the list of choices from the enum
	printf("The motor states are the following: \n");
	printf("-----------------------------------\n");	// the user must choose from as a little menu!
	printf("START Press 0\n");								
	printf("PULSE Press 1\n");
	printf("STOP  Press 2\n");
	printf("Clockwise rotation Press 3\n");
	printf("CounterClockwise rotation Press 4\n");
	printf("Low Speed (5%%) Press 5\n");
	printf("Full Speed (100%%) Press 6\n");
	printf("EXIT Press 7\n");
	printf("===================================\n\n");
	printf("Enter a state: \n");
	

	while (choice != EXIT)	// The while loop's only condition to execute is that the first number entered in  
	{						// CAN'T be 3 for EXIT otherwise the program stops running!	As long as the first number 
							// going in isn't 3 the while loop will start immediately. So, technically this 
							// first number can be anything but 3 to start!				


		scanf_s("%d", &choice);	// The user's choice get put into the variable choice!

		
		if (choice <= -1 || choice >= 8)	// This makes sure that user enters the correct numbered choices or it the program will fight 
		{									// back!
			printf("That choice doesn't exist try again!\n\n");
		}
		else
		{
			MotorState = (enum MotorCommands)choice;	// This tells the program to accept the user's input and associate
														// it with the enum list as choice!

			switch (MotorState)						// This sets up the cases depending on the option that the user
			{										// chooses!
			case START:
				if (Motor1.powerOn == 1)	// This checks to see whether the motor is powered on!
				{								
					printf("The motor is already ON!\n\n");	
				}
				else
				{ 
					printf("The motor is now ON! Select an operating mode:\n\n");
					Motor1.powerOn = 1;
				}										
				printf("Enter a state: \n");
				break;

			case PULSE:					// Here's another example of the if-else statement by means of reading whether or not the motor is
				if (Motor1.powerOn == 0)// one before it will emulate the motor pulsing
				{
					printf("Please turn the motor ON before selecting PULSE!\n");
				}
				else if (Motor1.status == PULSING)	// This prints out if the motor is already is pulsating
				{
					printf("The motor is already pulsing, do you want to select a different state?\n\n");
				}
				else if (Motor1.Direction == NO_DIRECTION || Motor1.speed == 0)
				{
					printf("Please select a direction and speed before pulsing!\n\n");
				}
				else
				{
					if (Motor1.Direction == CLOCKWISE)		// this checks what's directions the pulsating will go!
					{
						printf("Motor is now pulsing clockwise at %d%% speed!\n\n", Motor1.speed);
					}
					else
					{
						printf("Motor is now pulsing counterclockwise at %d%% speed!\n\n", Motor1.speed);
					}
					Motor1.status = PULSING;
				}
				printf("Enter another state: \n");
				break;

			case STOP:							// Prevents unnecessary STOP commands when the motor is already stationary
				if (Motor1.status == STOPPED)	
				{
					printf("The motor is already stopped!\n\n");
				}
				else
				{
					printf("Motor is STOPPING\n\n");
					Motor1.status = STOPPED;
				}
				printf("Enter another state: \n");
				break;

			case SET_CLOCKWISE:		// This is for setting up the clockwise direction after the motor has been turned on!
				if (Motor1.powerOn == 0)
				{
					printf("Please turn the motor ON before selecting a direction!\n\n");
				}
				else if (Motor1.Direction == CLOCKWISE)		// Clockwise is used to tell the program which direction
				{											// to store in the Motor1.Direction variable
					printf("The motor's direction is already set to clockwise, enter a different option!\n\n");
				}
				else
				{
					printf("The motor's direction is now set to Clockwise!\n\n");
					Motor1.Direction = CLOCKWISE;		// Here is where it gets stored!
				}
				printf("Enter a different state: \n");
				break;

			case SET_COUNTERCLOCKWISE:		// This does the same as the above case but for the counterclockwise direction 
				if (Motor1.powerOn == 0)
				{
					printf("Please turn the motor ON before selecting a direction!\n\n");
				}
				else if (Motor1.Direction == COUNTERCLOCKWISE)	// This checks if the rotation is already 
				{											// counterclockwise or not
					printf("The motor's direction is already set to Counterclockwise!\n\n");
				}
				else
				{
					printf("The motor's direction is now set to Counterclockwise!\n\n");
					Motor1.Direction = COUNTERCLOCKWISE;	// Here's where it gets stored!
				}
				printf("Enter a different state: \n");
				break;

			case SET_LOW_SPEED:		// This is for the slower speed prompt 
				if (Motor1.powerOn == 0)
				{
					printf("Please turn the motor ON before selecting a speed!\n");
				}
				else if (Motor1.speed == 5)
				{
					printf("The motor is already rotating at 5%% speed, select another speed!\n\n");
				}
				else
				{
					printf("The motor is now rotating at 5%% speed!\n\n");
					Motor1.speed = 5;
				}	
				printf("Enter a different speed! \n");
				break;

			case SET_FULL_SPEED:		// This is for the full speed prompt
				if (Motor1.powerOn == 0)
				{
					printf("Please turn the motor ON before selecting a speed!\n");
				}
				else if (Motor1.speed == 100)
				{
					printf("The motor is already rotating at Full speed, select another speed!\n\n");
				}
				else
				{
					printf("The motor is now rotating at Full speed!\n\n");
					Motor1.speed = 100;
				}
				printf("Enter a different speed! \n");
				break;

			case EXIT:										// This case simply exits the program!
				printf("You have exited the Program!\n\n");
				break;
			}
		}
	}
	return 0;				
}