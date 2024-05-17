#include "Quicksort.h"
#include "Vector-1.h"
#include "Random.h"
#include <iostream>

using namespace std;

int main()
{
	Vector<int> VectorToSort;
	for (int i = 0; i < 25; i++)
	{
		int RandomNumber;
		while (true)
		{
			RandomNumber = rand_int(1, 100);
			for (int j = 0; j < VectorToSort.size(); j++)
			{
				if (RandomNumber == VectorToSort[j])
				{
					break;
				}
			}
			break;
		}


		VectorToSort.push_back(RandomNumber);
	}
	cout << "Before sorting: ";
	for (int i = 0; i < VectorToSort.size(); i++)
	{
		cout << VectorToSort[i] << " ";
	}
	cout << endl;
	cout << "Sorting by Quicksort... " << endl;
	Quicksort(VectorToSort, 0, VectorToSort.size() - 1);
	cout << "After sorting: ";
	for (int i = 0; i < VectorToSort.size(); i++)
	{
		cout << VectorToSort[i] << " ";
	}
}