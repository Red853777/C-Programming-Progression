/*Title: Incrementing Factorial Calculator
* 
* Purpose: Calculates factorials from 0 to up to the number entered by the user utilizing nested for loops
* 
* Author: Nik Haas
*/
#include <iostream>

using namespace std;

void IncrementingFactorial(auto number);

int main(void)
{
	auto number = 0;

	cout << "Enter a number: ";	// This simply prompts the user to enter in any number of the user's choosing
	cin >> number;	// This is what takes that number in 

	if (number <= 0)	// This if else statement filters out any negative number and 0
	{
		cout << "The number entered is an undefined factorial ";
		cout << endl;
	}
	else
		IncrementingFactorial(number);		// This is what sends that number to the function down below to perfrom the factorial math

	return 0;
}

void IncrementingFactorial(auto number)
{
	long long factorial = 1;	// factorial stores the accumulated mathematical result, 

	cout << "The Factorial of: " << number << endl;
	cout << "-------------------" << endl;
	cout << "0!= " << factorial << endl;	// This displays the start of the iteration but outside of the loop due to 0! being 1

	for (int i = 1; i <= number; i++)		// This outter for loop starts the iteration through multiplacion from 1 and increases to the number of the 
	{										// uers choosing, then stores that multiple in the variable factorial 
		cout << i << "!= ";		// This prints out the start of the iteration and grows depending on what was entered
		factorial *= i;		// This is where the math happens for the factorial of multiples 

		for (int j = 1; j <= i; j++)	// This is what tracks the ammount of numbers that will be displayed to demonstrate the amount of  
		{								// numbers involved for the factorial
			cout << j << " ";	// This prints the numbers per each factorial out 
			if (j < i)	// This makes sure that j must stay behind i before the multiply sign gets displayed down below
				cout << "* ";
		}
		cout << "= " << factorial << endl;		// This line while still inside the outer for loop prints summed muliplicity of factorial
												// since it's being used after the math line above
	}
	cout << endl;

}