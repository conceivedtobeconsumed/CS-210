// main.cpp
// Driver for the Airgead Banking investment calculator. Keeps logic light:
// gathers input, hands it to an Investment object, and prints the reports.
//
// Author: [Your Name]
// Date:   [Enter date]

#include "Investment.h"

#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

// Read a positive real number, re-prompting until the input is valid. Used for
// the dollar amounts and the interest rate.
double promptForDouble(const string& t_label)
{
	double value = 0.0;
	bool valid = false;

	while (!valid)
	{
		cout << t_label;
		cin >> value;

		if (cin.fail() || value < 0.0)
		{
			// Clear the error flag and drop the bad line, then try again.
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "  Please enter a non-negative number." << endl;
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			valid = true;
		}
	}

	return value;
}

// Read a whole number of years greater than zero, re-prompting on bad input.
int promptForYears(const string& t_label)
{
	int value = 0;
	bool valid = false;

	while (!valid)
	{
		cout << t_label;
		cin >> value;

		if (cin.fail() || value <= 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "  Please enter a whole number greater than zero." << endl;
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			valid = true;
		}
	}

	return value;
}

// Collect all four values from the user and load them into the object. The
// setters validate again and throw if something slips through, so we guard
// with try/catch and re-ask on failure.
void gatherInput(Investment& t_investment)
{
	cout << "**********************************" << endl;
	cout << "********** Data Input ************" << endl;

	bool loaded = false;
	while (!loaded)
	{
		try
		{
			t_investment.setInitialInvestment(
			    promptForDouble("Initial Investment Amount: "));
			t_investment.setMonthlyDeposit(
			    promptForDouble("Monthly Deposit: "));
			t_investment.setAnnualInterestRate(
			    promptForDouble("Annual Interest: "));
			t_investment.setNumberOfYears(
			    promptForYears("Number of years: "));
			loaded = true;
		}
		catch (const invalid_argument& ex)
		{
			// Report the issue and let the loop restart the questions.
			cout << "Input error: " << ex.what() << " Please try again." << endl;
		}
	}
}

// Pause so the user can read the input screen before the reports appear.
void pressAnyKeyToContinue()
{
	cout << "Press any key to continue . . .";
	cin.get();
	cout << endl;
}

int main()
{
	bool runAgain = true;

	while (runAgain)
	{
		Investment investment;

		gatherInput(investment);
		pressAnyKeyToContinue();

		cout << "========================================================" << endl;
		cout << "   Balance and Interest Without Additional Monthly Deposits" << endl;
		cout << "========================================================" << endl;
		investment.printReport(false);

		cout << "========================================================" << endl;
		cout << "   Balance and Interest With Additional Monthly Deposits" << endl;
		cout << "========================================================" << endl;
		investment.printReport(true);

		// Let the user try different numbers (functional requirement 3).
		cout << "Would you like to run another projection? (Y/N): ";
		char choice = 'N';
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		runAgain = (choice == 'Y' || choice == 'y');
		cout << endl;
	}

	cout << "Thank you for using the Airgead Banking investment calculator." << endl;
	return 0;
}
