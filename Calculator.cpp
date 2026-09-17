/*
 * Calculator.cpp
 * 
 *  Purpose: Perform basic arithmetic for single integers.
 *  Date: 20260913
 *  Author: David Lantz
 */

#include <iostream>

using namespace std;

// FIX (syntax): "void main()" I am not familiar with. The program must return an int,
// so main is declared as "int main()" and returns 0 when successful.
int main()
{
	// FIX: Removed the unused "char statement[100];" variable. Not necessary to logic.

	// FIX (logic): The assignment states the calculator must accept "integers
	// or doubles." Declaring them as double corrects.
	double op1, op2;
	char operation;

	// FIX (syntax): The requirement states the program needs 
	// to accept both cases for chars "Y"/"y" or "N"/"n", 
	// and the statement needs a terminating semicolon.
	char answer = 'Y';

	// FIX (logic): The loop now continues on either case value of 'answer'.
	while (answer == 'y' || answer == 'Y')
	{
		cout << "Enter expression" << endl;

		// FIX (logic): Now reads left-to-right: op1, operation, op2.
		cin >> op1 >> operation >> op2;

		// FIX (syntax/logic): Found the string "+" instead of the char '+', 
		// had a stray semicolon and used >> instead of <<.
		if (operation == '+')
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;

		// FIX (syntax): Removed the stray semicolon after the if condition 
		// and corrected the output stream operator to <<.
		if (operation == '-')
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;

		// FIX (logic/syntax): The original printed the " / " symbol; the label is
		// now " * " and the missing terminating semicolon was added.
		if (operation == '*')
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;

		// FIX (logic/run-time): The label is now " / ". Dividing by zero is a
		// run-time error, so the program checks for a zero divisor first.
		if (operation == '/')
		{
			if (op2 != 0)
				cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
			else
				cout << "Error: division by zero" << endl;
		}

		// Requirement: after each expression, ask whether to continue.
		cout << "Do you wish to evaluate another expression? (Y/N) " << endl;
		cin >> answer;
	}

	// FIX: Requirement states that when the user answers "N" or "n" the program
	// terminates with the message "Program Finished." This statement was missing.
	cout << "Program Finished." << endl;

	// FIX (syntax): int main must return a value.
	return 0;
}
