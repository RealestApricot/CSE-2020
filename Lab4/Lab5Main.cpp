#include <iostream>
#include <vector>
#include "RandomV.h"
#include "List.h"

using namespace std;

template <typename DataType>
void print_list(List<DataType>);

List<int> max_subseq_sum_collect(const List<int>&, int&);

int main()
{
	List<int> mylst = List<int>();
	vector<int> rnums = vector<int>();
	random_vector(25, 1, 100, rnums, 4);
	for (int i = 0; i < rnums.size(); i++)
		mylst.PushBack(rnums[i]);
	cout << "My list of random numbers: " << endl;
	print_list(mylst);

	int maxsubsum;
	List<int> maxsubseq = max_subseq_sum_collect(mylst, maxsubsum);

	cout << endl;
	cout << "The max subseq sum: " << maxsubsum << endl << endl;
	cout << "The max subsum squence: " << endl;
	print_list(maxsubseq);
	cout << endl << endl;

	List<int>::Iterator Iteration1 = maxsubseq.Begin();

	for (; Iteration1 != maxsubseq.End(); ++Iteration1)
	{
		List<int>::Iterator Iteration2 = mylst.Begin();
		while (Iteration2 != mylst.End())
		{
			if (*Iteration1 == *Iteration2)
			{
				int togo = *Iteration2;
				Iteration2 = mylst.Erase(Iteration1);
				mylst.Insert(Iteration2, 0);
			}
			else
				++Iteration2;
		}
	}

	cout << endl << endl;
	cout << "My list after replacing all max subseq values with 0: " << endl;
	print_list(mylst);
	cout << endl << endl;


	return 0;
}


template <typename DataType>
void print_list(List<DataType> lst)
{
	cout << endl;
	typename List<DataType>::Iterator Iteration;
	for (Iteration = lst.Begin(); Iteration != lst.End(); ++Iteration)
		cout << *Iteration << " ";
	cout << endl;
}

List<int> max_subseq_sum_collect(const List<int> &lst, int &max)
{
	int maxsum = 0;
	int localsum = 0;
	List<int> maxseq; // Reuse the same list

	List<int>::Iterator Iteration = lst.Begin();
	for (; Iteration != lst.End(); ++Iteration)
	{
		localsum += *Iteration;
		maxseq.PushBack(*Iteration); // Add element to the same list

		if (localsum > maxsum)
		{
			maxsum = localsum;
			maxseq.ClearList();    // Clear the list before adding new elements
			maxseq.PushBack(*Iteration); // Start the new maximum sequence
		}
		else if (localsum < 0)
		{
			localsum = 0;
			maxseq.ClearList();
		}
	}

	max = maxsum;
	return maxseq;
}
