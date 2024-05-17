// For CSE 2020 Lab 7,8
// KV, Spring 2024

#include <iostream>
#include <algorithm>
#include "Vector-1.h"
#include "List.h"
#include "Random-1.h"
#include "Searching-1.h"
#include "Utilities-1.h"

using namespace std;


int main()
{
	rand_seed();
	Vector<int> myvec;
	random_vector_norep(25, 1, 250, myvec, 0);

	// sorting to set up for binary search runs ...
	// sort(myvec.begin(), myvec.end());

	List<int> mylst;
	for (int i = 0; i < myvec.size(); i++)
		mylst.push_back(myvec[i]);

	// three target values to search
	Vector<int> targets;
	targets.push_back(myvec[rand_int(0,25)]);
	targets.push_back(myvec[rand_int(0,25)]);
	targets.push_back(333);
	
	cout << endl;
	cout << "Sequence of random numbers (both in Vector and List):" << endl;
	print_Vector(myvec);
	cout << endl;

	for (int i = 0; i < targets.size(); i++)
	{
		cout << endl;
		cout << "Linear Search of Vector for target value " << targets[i] << ":\t";
	
		if (LinearSearch(myvec, targets[i]) != -1)
			cout << "Found :-)" << endl;
		else
			cout << "Not found :-(" << endl;

		cout << endl;
		cout << "Linear Search of List for target value " << targets[i] << ":\t";

		if (LinearSearch(mylst, targets[i]) != mylst.end())
			cout << "Found :-)" << endl;
		else
			cout << "Not found :-(" << endl;
	}
	cout << endl << endl;

	for (int i = 0; i < targets.size(); i++)
	{
		cout << endl;
		cout << "Recursive Linear Search of Vector for target value " << targets[i] << ":\t";

		if (RecursiveLinearSearch(0, myvec, targets[i]) != -1)
			cout << "Found :-)" << endl;
		else
			cout << "Not found :-(" << endl;

		cout << endl;
		cout << "Recursive Linear Search of List for target value " << targets[i] << ":\t";

		if (RecursiveLinearSearch(mylst.begin(), mylst, targets[i]) != mylst.end())
			cout << "Found :-)" << endl;
		else
			cout << "Not found :-(" << endl;
	}

	cout << endl << endl;

	// for (int i = 0; i < targets.size(); i++)
	// {
	// 	cout << endl;
	// 	cout << "Iterative Binary Search of Vector for target value " << targets[i] << ":\t";

	// 	if (binary_search_V(myvec, targets[i]) != -1)
	// 		cout << "Found :-)" << endl;
	// 	else
	// 		cout << "Not found :-(" << endl;
	// 	cout << endl;

	// 	cout << "Recursive Binary Search of List for target value " << targets[i] << ":\t";

	// 	if (rec_binary_search_V(0, myvec.size()-1, myvec, targets[i])  != -1)
	// 		cout << "Found :-)" << endl;
	// 	else
	// 		cout << "Not found :-(" << endl;
	// 	cout << endl;

	// }
	return 0;
}

