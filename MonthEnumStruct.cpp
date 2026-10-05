/*Title: MonthEnumStrut
  
  Purpose: To learn how to write a program using struct, enum, switch-case and If-else statements
		  to print out specific dates and take into account a none leap year. It prints out the specific months
		  as instructed then checks the dates to see what dates need to be increased by one day or one month!
  
  Author: Nik Haas
*/
#include <stdio.h>
// This allows things in the program to be printed! 

enum Month		// This allows the program to create list numbers associated with numbers: 0 - 11 (12)
{
	January,	// number 0 = January
	February,
	March, 
	April,
	May, 
	June,
	July,
	August,
	September,
	October,
	November,
	December	// number 11 = December
};

struct Dates	// This is what the format of the dates look like		
{
	enum Month month;	// Stores one of the month enum values (Jan, Feb, etc.)
	int day;			// Stores the day of the month (1, 2, 14, 28, etc) 
};

void printdate(struct Dates date);		// This is the prototype for the void printdate(struct Dates date) function

struct Dates nextday(struct Dates date);	// This is the prototype for the struct Dates nextday(struct Dates date) function

int main(void) 
{
	struct Dates date1;			// Here's where the work starts to happen! These lines create the actual date 
	date1.month = January;		// variables from the struct Dates. Each numbered variable takes a specific month
	date1.day = 1;				// that the directions asked to be print out and get saved within the main function!
								// date1 is not associated with the first monty of the year and 1st day of that month
	struct Dates date2;
	date2.month = February;
	date2.day = 28;

	struct Dates date3;
	date3.month = March;
	date3.day = 14;

	struct Dates date4;
	date4.month = October;
	date4.day = 31;

	struct Dates date5;
	date5.month = December;
	date5.day = 31;

	printdate(date1);		// These all tell the program to take everything stored inside date#'s and send it to 
	printdate(date2);		// the printdate function that's just after the first swicth case in the 2nd function.
	printdate(date3);		// It's what tells the program to print out the original month and days!
	printdate(date4);
	printdate(date5);

	printf("\nHere are the new dates\n");	// This creates the space and explains that the new dates are below
	printf("======================\n\n");	// Here's a little fancy line!

	struct Dates nextDate;		// This part creates another variable using Dates struct called nextDate	
	nextDate = nextday(date1);		// This lines like this one finds the next date to be printed
	printdate(nextDate);		// This sends that date to the case to be printed below the switch-case
	nextDate = nextday(date2);
	printdate(nextDate);
	nextDate = nextday(date3);
	printdate(nextDate);
	nextDate = nextday(date4);
	printdate(nextDate);
	nextDate = nextday(date5);
	printdate(nextDate);
	
	return 0;
}

void printdate(struct Dates date)		// Next here's the 2nd function that's connected to the prototype up top.
{										// Its job is to pull all the first dates given from Option 1 instructions
	switch (date.month)					// that were made in the main function and bring them into the switch case 
	{									// that is inside it!
		case January:
			printf("January ");			// Within the switch case each month has its own case! This is what 
			break;						// actually prints out each month!

		case February:
			printf("February ");
			break;

		case March:
			printf("March ");
			break;

		case April:
			printf("April ");
			break;

		case May:
			printf("June ");
			break;

		case June:
			printf("June ");
			break;

		case July:
			printf("July ");
			break;

		case August:
			printf("August ");
			break;

		case September:
			printf("September ");
			break;

		case October:
			printf("October ");
			break;

		case November:
			printf("November ");
			break;

		case December:
			printf("December ");
			break;
	};

	printf("%d\n", date.day);		// This prints out the first days that are associated with the months as 
									// instructed!
}

struct Dates nextday(struct Dates date)	// This setups up the next day and month for the specific dates as requested 
{
	int maxDays = 0;		// This makes a temperary int called maxDays that remembers the maximum number of days allowed
						// in whichever month was passed into nextday().
	switch (date.month)					// This switch case asks what month did nextday receive?
	{
		case January:
			maxDays = 31;
			break;

		case February:
			maxDays = 28;
			break;

		case March:
			maxDays = 31;
			break;

		case April:
			maxDays = 30;
			break;

		case May:
			maxDays = 31;
			break;

		case June:
			maxDays = 30;
			break;
		
		case July:
			maxDays = 31;
			break;

		case August:
			maxDays = 31;
			break;

		case September:
			maxDays = 30;
			break;

		case October:
			maxDays = 31;
			break;

		case November:
			maxDays = 30;
			break;

		case December :
			maxDays = 31;
			break;
	}

	if (date.day < maxDays)		// Is the current day smaller than the maximum number of days in this month?
	{
		date.day++;		// If not add the day by one
	}

	else		// This only happens when the first condition is false by means of the the month has ended
	{						
		date.day = 1;
		
		if (date.month == December)		// This handles the end of the year specifically, if the month is December
		{								// It get checked, then the day turns to 1 and the month gets turned to Jan.
			date.month = January;
		}

		else		// This else statement handles every other month if the month isn't the end of the year or 
		{			// or a leap year this is how the other months get changed to get increased by 1 day!
			date.month = (enum Month)(date.month + 1);
		}
	}
	return date;
}