// Lab10Main.cpp
// KV for CSE 2020 in Spring 2024

#include <iostream>
#include "BinarySearchTreeLab9-1.h"  // completed version
#include "Random-1.h"
using namespace std;

int main()
{
	rand_seed();

	Vector<int> MyVector;
	cout << "Creating a random vector of integers from 1 - 250 of length 25" << endl;
	for (int i = 1; i <= 25; i++)
	{
		MyVector.push_back(rand_int(1, 250));
	}
	cout << "Vector (unsorted): ";
	for (int i = 0; i < MyVector.size(); i++)
	{
		cout << MyVector[i] << " ";
	}

	cout << "Sorting Vector using BinarySearchTree" << endl;
	BinarySearchTree<int> SortingTree;
	for (int i = 0; i < MyVector.size(); i++)
	{
		SortingTree.insert(MyVector[i]);
	}
	cout << "BST of values from Vector: " << endl;
	SortingTree.printElements();

	Vector<int> SortedVector;
	while (SortingTree.isEmpty() == false)
	{
		cout << "Removing Minimum and Adding to Vector" << endl;
		int Minimum = SortingTree.findMin();
		SortedVector.push_back(Minimum);
		SortingTree.remove(Minimum);
	}
	cout << "Sorted Vector: ";
	for (int i = 0; i < SortedVector.size(); i++)
	{
		cout << SortedVector[i] << " ";
	}
	
	return 0;
}