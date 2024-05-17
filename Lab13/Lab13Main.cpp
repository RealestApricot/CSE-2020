#include "Vector-13.h"
#include "Random.h"
#include "Sorting.h"
#include <iostream>

using namespace std;

int main()
{
	Vector<int> MyVector(0);
	Vector<int> MyVector2(0);
	Vector<int> MyVector3(0);
	random_vector(25, 1, 100, MyVector, 0);
	random_vector(25, 1, 100, MyVector2, 0);
	random_vector(25, 1, 100, MyVector3, 0);

	cout << "MyVector: " << endl;
	for (int i = 0; i < MyVector.size(); i++)
	{
		cout << MyVector[i] << ", ";
	}
	cout << endl;

	InsertionSort(MyVector);

	cout << "InsertionSorted MyVector: " << endl;
	for (int i = 0; i < MyVector.size(); i++)
	{
		cout << MyVector[i] << ", ";
	}
	cout << endl;

	cout << "MyVector2: " << endl;
	for (int i = 0; i < MyVector.size(); i++)
	{
		cout << MyVector2[i] << ", ";
	}
	cout << endl;

	SelectionSort(MyVector2);

	cout << "SelectionSorted MyVector2: " << endl;
	for (int i = 0; i < MyVector.size(); i++)
	{
		cout << MyVector2[i] << ", ";
	}

	cout << "MyVector3: " << endl;
	cout << endl;
	
	for (int i = 0; i < MyVector.size(); i++)
	{
		cout << MyVector3[i] << ", ";
	}
	cout << endl;

	MergeSort(MyVector3);

	cout << "MergeSorted MyVector2: " << endl;
	for (int i = 0; i < MyVector.size(); i++)
	{
		cout << MyVector3[i] << ", ";
	}

	return 0;
}