/*
 * MadLibs.cpp
 *
 *  Date: [Enter date]
 *  Author: [Your Name]
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word;
	int number;

	// Read a word/number pair each loop. Stop as soon as the word is "quit"
	// (the integer that follows "quit" is read but ignored).
	while (cin >> word >> number)
	{
		if (word == "quit")
			break;

		cout << "Eating " << number << " " << word
		     << " a day keeps you happy and healthy." << endl;
	}

	return 0;
}
