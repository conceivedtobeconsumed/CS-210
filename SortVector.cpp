/*
 * SortVector.cpp
 *
 * Reads a count followed by that many integers, sorts them highest to lowest,
 * and prints each one followed by a comma.
 *
 *  Date: [Enter date]
 *  Author: [Your Name]
 */

#include <iostream>
#include <vector>

using namespace std;

// Sort the vector in place, highest to lowest. Bubble sort: walk the list over
// and over, swapping any neighbors that are out of order, until nothing swaps.
void SortVector(vector<int>& myVec)
{
	for (unsigned int i = 0; i < myVec.size(); i++)
	{
		for (unsigned int j = 0; j < myVec.size() - 1 - i; j++)
		{
			// Descending order, so swap when the left value is the smaller one.
			if (myVec[j] < myVec[j + 1])
			{
				int temp = myVec[j];
				myVec[j] = myVec[j + 1];
				myVec[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int count;
	cin >> count;   // first number tells us how many follow

	vector<int> numbers;
	for (int i = 0; i < count; i++)
	{
		int value;
		cin >> value;
		numbers.push_back(value);
	}

	SortVector(numbers);

	// Every value gets a trailing comma, last one included.
	for (unsigned int i = 0; i < numbers.size(); i++)
		cout << numbers[i] << ",";
	cout << endl;

	return 0;
}
