#include <iostream>
#include "Random-3.h"
#include "BST_Set.h"

using namespace std; 

Vector<int> permute(Vector<int>);


int main()
{
	// HW4 
	Vector<int> mult31;
	Vector<int>  mult32;

	cout << "One set SetA of multiples of 3:" << endl;
	for (int i = 1; i <= 12; i++)
	{
		cout << i * 3 << " ";
		mult31.push_back(i * 3);
	}
	cout << endl << endl;
	cout << "Another set SetB of multiples of 3:" << endl;
	for (int i = 6; i <= 18; i++)
	{
		cout << i * 3 << " ";
		mult32.push_back(i * 3);
	}
	cout << endl << endl;

	Vector<int> perm31 = permute(mult31);
	Vector<int> perm32 = permute(mult32);

	cout << "Both sets permuted before value inserstion ..." << endl << endl;
	for (int i = 0; i < perm31.size(); i++)
		cout << perm31[i] << " ";
	cout << endl << endl;

	for (int i = 0; i < perm32.size(); i++)
		cout << perm32[i] << " ";
	cout << endl << endl;

	Set<int> SetA, SetB;

	for (int i = 0; i < perm31.size(); i++)
		SetA.insert(perm31[i]);
	for (int i = 0; i < perm32.size(); i++)
		SetB.insert(perm32[i]);

	Set<int> theunion = SetA.set_union(SetB);
	Set<int> thesect = SetA.set_intersection(SetB);
	Set<int> diff1 = SetA.set_difference(SetB);
	Set<int> diff2 = SetB.set_difference(SetA);

	cout << "The union:" << endl;
	theunion.printSet();
	cout << endl << endl;
	cout << "The intersection:" << endl;
	thesect.printSet(); 
	cout << endl << endl;
	cout << "Difference SA - SB:" << endl;
	diff1.printSet(); 
	cout << endl << endl;
	cout << "Difference SB - SA:" << endl;
	diff2.printSet(); 
	cout << endl << endl;

	return 0;
}

// produces a random permutation of vector elements
Vector<int> permute(Vector<int> vec)
{
	rand_seed();
	Vector<int> perm;
	int left = 0;
	while (left < vec.size())
	{
		int pick = rand_int(left, vec.size() - 1);
		perm.push_back(vec[pick]);
		std::swap(vec[left], vec[pick]);
		left++;
	}
	return perm;
}

