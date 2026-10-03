/*
 * Clock.cpp
 *
 * Shows a 12-hour and 24-hour clock side by side. The user can bump the time
 * forward by an hour, minute, or second from a menu until they quit.
 *
 *  Date: 20260916
 *  Author: David Lantz
 */

#include <iostream>
#include <string>
#include <limits> // Added to support input validation.

using namespace std;

// Turn a number into a two-char string so "3" shows up as "03".
string twoDigitString(int value)
{
	string result = to_string(value);
	if (result.length() < 2)
		result = "0" + result;
	return result;
}

// Build the 12-hour string. Anything from 13-23 folds back into 1-12, and both
// 0 and 12 read as 12 (midnight and noon).
string format12Hour(int hours, int minutes, int seconds)
{
	string period = (hours < 12) ? "A M" : "P M";
	int displayHour = hours % 12;
	if (displayHour == 0)
		displayHour = 12;

	return twoDigitString(displayHour) + ":" + twoDigitString(minutes) + ":" +
	       twoDigitString(seconds) + " " + period;
}

// Straight 24-hour string, no conversion needed.
string format24Hour(int hours, int minutes, int seconds)
{
	return twoDigitString(hours) + ":" + twoDigitString(minutes) + ":" + twoDigitString(seconds);
}

// Print both clocks next to each other in their little boxes.
void displayClocks(int hours, int minutes, int seconds)
{
	string time12 = format12Hour(hours, minutes, seconds);
	string time24 = format24Hour(hours, minutes, seconds);

	cout << "**************************   **************************" << endl;
	cout << "*      12-Hour Clock     *   *      24-Hour Clock     *" << endl;
	cout << "*       " << time12 << "     *   *        " << time24
	     << "        *" << endl;
	cout << "**************************   **************************" << endl;
}

void displayMenu()
{
	cout << endl;
	cout << "**************************" << endl;
	cout << "* 1 - Add One Hour       *" << endl;
	cout << "* 2 - Add One Minute     *" << endl;
	cout << "* 3 - Add One Second     *" << endl;
	cout << "* 4 - Exit Program       *" << endl;
	cout << "**************************" << endl;
}

// Bump the hour, wrapping around midnight.
void addHour(int &hours)
{
	hours = (hours + 1) % 24;
}

// Bump the minute, rolling into the next hour when we pass 59.
void addMinute(int &hours, int &minutes)
{
	minutes++;
	if (minutes > 59)
	{
		minutes = 0;
		addHour(hours);
	}
}

// Bump the second, letting it cascade up through minutes and hours.
void addSecond(int &hours, int &minutes, int &seconds)
{
	seconds++;
	if (seconds > 59)
	{
		seconds = 0;
		addMinute(hours, minutes);
	}
}

// Ask for the starting time. Anything out of range just falls back to 0 so we
// never start with a bogus clock.
void getUserInput(int &hours, int &minutes, int &seconds)
{
	cout << "Enter the starting hour (0-23): ";
	cin >> hours;
	cout << "Enter the starting minute (0-59): ";
	cin >> minutes;
	cout << "Enter the starting second (0-59): ";
	cin >> seconds;

	if (hours < 0 || hours > 23) hours = 0;
	if (minutes < 0 || minutes > 59) minutes = 0;
	if (seconds < 0 || seconds > 59) seconds = 0;
}

int main()
{
	int hours, minutes, seconds;
	int choice = 0;

	getUserInput(hours, minutes, seconds);

	// Show the clocks, show the menu, act on the pick, repeat until they exit.
	do
	{
		displayClocks(hours, minutes, seconds);
		displayMenu();

		cout << "Enter your choice: ";
		cin >> choice;

		// I fat-fingered inputs and included an 'f' (str) as input and the app
		// responded with infinite loop of 'invalid character'.  Added input validation
		// based on discussion from colleague where I asked for help.
		if (cin.fail())
		{
			cin.clear(); // clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
			cout << "Invalid choice. Please select 1-4." << endl;
			continue;
		}
		
		// Switch to manage menu option responses.
		switch (choice)
		{
		case 1:
			addHour(hours);
			break;
		case 2:
			addMinute(hours, minutes);
			break;
		case 3:
			addSecond(hours, minutes, seconds);
			break;
		case 4:
			cout << "Program Finished." << endl;
			break;
		default:
			cout << "Invalid choice. Please select 1-4." << endl;
			break;
		}
	} while (choice != 4);

	return 0;
}
