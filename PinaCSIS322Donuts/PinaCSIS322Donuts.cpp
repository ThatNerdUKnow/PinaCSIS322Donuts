// Program name: PINACSIS322Donuts
// Date written: 8/29/19
// Programmer Name: Brandon Pina
// Description: This program takes a donut order and calculates a running total then displays the total cost of the order after the user no longer desires to order more donuts

#include "pch.h"
#include <iostream>

using namespace std;
int main()
{
	//Declare constants

	const double REGULAR_DONUT_COST = .50;
	const double DELUXE_DONUT_COST = .75;
	const int MIN_DONUTS = 1;
	const int MAX_DONUTS = 144;

	char donutType;
	int numDonuts;
	double totalCost = 0;
	char processAgain;

	// Print program title

	cout << "Delbert's Donuts" << endl << endl;

	// Display input prompt
	do
	{
		do
		{
			cout << "Enter donut type (R -Regular) or (D -Deluxe) ";

			// Take input for donut type

			cin >> donutType;

			if ((toupper(donutType) != 'D' && toupper(donutType) != 'R'))
			{
				cout << endl << "Donut type must be either 'R' -Regular or 'D' -Deluxe" << endl;
			}



		} while (toupper(donutType) != 'D' && toupper(donutType) != 'R');
		//while ((toupper(donutType) != 'R') || (toupper(donutType) != 'D'));


		do
		{
			// Reset cin in case user inputs anything other than an integer

			cin.clear();
			cin.ignore();

			// Display input prompt for number of donuts

			cout << "Enter number of donuts purchased " << endl;

			// Take input for donut quantity

			cin >> numDonuts;

			// Show conditional error messages

			if (!cin)
			{
				// User inputs anything besides an integer

				cout << "Only numeric values are allowed" << endl;

			}
			else if (numDonuts < MIN_DONUTS || numDonuts > MAX_DONUTS)
			{
				// User input an integer outside of our range

				cout << "Donuts purchased must be between " << MIN_DONUTS << " and " << MAX_DONUTS << endl;
			}


		} while (!cin || (numDonuts < MIN_DONUTS || numDonuts > MAX_DONUTS));

		// All of our validation is done, time to add our subtotal to the order

		if (toupper(donutType) == 'D')
		{
			totalCost += numDonuts * DELUXE_DONUT_COST;
		}
		else if (toupper(donutType) == 'R')
		{
			totalCost += numDonuts * REGULAR_DONUT_COST;
		}
		 
		// Show user their order total so far

		cout << "The cost of your order is: " << totalCost << endl;

		// Ask if user wants to input another order

		do
		{
			
			cout << "Process another order? (Y/N) " << endl;
			cin >> processAgain;

			if (toupper(processAgain) != 'Y' && toupper(processAgain) != 'N')
			{
				cout << "You must enter either 'Y' or 'N' " << endl;
			}

		} while (toupper(processAgain) != 'Y' && toupper(processAgain) != 'N');


	} while (toupper(processAgain) == 'Y');
	
	cout.precision(2);
	cout << "Your total is: $" << totalCost << " Thank you for shopping at Delbert's Donuts";



	
}

