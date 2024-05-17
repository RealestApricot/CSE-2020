#ifndef SORTING_H_
#define SORTING_H_

#include "Vector-13.h"
using namespace std;

template <typename DataType>

void InsertionSort(Vector<DataType>& VectorToSort)
{
	for (int i = 1; i < VectorToSort.size(); i++)
	{
		DataType temp = VectorToSort[i];
		int j;
		for (j = i; j > 0 && temp < VectorToSort[j - 1]; j--)
		{
			VectorToSort[j] = VectorToSort[j - 1];
		}
		VectorToSort[j] = temp;
	}
}

template <typename DataType>
void SelectionSort(Vector<DataType>& VectorToSort)
{
	int minIndex;
	for (int i = 0; i < VectorToSort.size(); i++)
	{
		minIndex = i;
		for (int j = i; j < VectorToSort.size(); j++)
		{
			if (VectorToSort[j] < VectorToSort[minIndex])
			{
				minIndex = j;
			}
		}
		std::swap(VectorToSort[i], VectorToSort[minIndex]);
	}
}

template <typename DataType>
void MergeSort(Vector<DataType>& VectorToSort)
{
	if (VectorToSort.size() > 1)
	{
		Vector<DataType> left;
		Vector<DataType> right;
		int mid = VectorToSort.size() / 2;
		for (int i = 0; i < mid; i++)
		{
			left.push_back(VectorToSort[i]);
		}
		for (int i = mid; i < VectorToSort.size(); i++)
		{
			right.push_back(VectorToSort[i]);
		}
		MergeSort(left);
		MergeSort(right);
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < left.size() && j < right.size())
		{
			if (left[i] < right[j])
			{
				VectorToSort[k] = left[i];
				i++;
			}
			else
			{
				VectorToSort[k] = right[j];
				j++;
			}
			k++;
		}
		while (i < left.size())
		{
			VectorToSort[k] = left[i];
			i++;
			k++;
		}
		while (j < right.size())
		{
			VectorToSort[k] = right[j];
			j++;
			k++;
		}
	}
}

#endif
