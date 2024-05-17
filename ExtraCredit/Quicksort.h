#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include "Vector-1.h"

using namespace std;

template <typename DataType>
void InsertionSort(Vector<DataType> &VectorToSort, int LeftIndex, int RightIndex)
{
	for (int i = LeftIndex + 1; i <= RightIndex; i++)
	{
		DataType Temp = VectorToSort[i];
		int j = i - 1;
		while (j >= LeftIndex && VectorToSort[j] > Temp)
		{
			VectorToSort[j + 1] = VectorToSort[j];
			j--;
		}
		VectorToSort[j + 1] = Temp;
	}
}

template <typename DataType>
const DataType &Median(Vector<DataType> &VectorToSort, int LeftIndex, int RightIndex)
{
	int MiddleIndex = (LeftIndex + RightIndex) / 2;
	if (VectorToSort[MiddleIndex] < VectorToSort[LeftIndex])
	{
		std::swap(VectorToSort[MiddleIndex], VectorToSort[LeftIndex]);
	}
	if (VectorToSort[RightIndex] < VectorToSort[LeftIndex])
	{
		std::swap(VectorToSort[RightIndex], VectorToSort[LeftIndex]);
	}
	if (VectorToSort[RightIndex] < VectorToSort[MiddleIndex])
	{
		std::swap(VectorToSort[RightIndex], VectorToSort[MiddleIndex]);
	}
	std::swap(VectorToSort[MiddleIndex], VectorToSort[RightIndex - 1]);
	return VectorToSort[RightIndex - 1];
}

template <typename DataType>
void Quicksort(Vector<DataType> &VectorToSort, int LeftIndex, int RightIndex)
{
	if (LeftIndex < RightIndex)
	{
		const DataType &Pivot = Median(VectorToSort, LeftIndex, RightIndex);
		int i = LeftIndex, j = RightIndex;
		while (true)
		{
			while (VectorToSort[++i] < Pivot)
			{
			}
			while (VectorToSort[--j] > Pivot)
			{
			}
			if (i >= j)
			{
				break;
			}
			std::swap(VectorToSort[i], VectorToSort[j]);
		}
		Quicksort(VectorToSort, LeftIndex, j);
		Quicksort(VectorToSort, j + 1, RightIndex);
	}
	else
	{
		InsertionSort(VectorToSort, LeftIndex, RightIndex);
	}
}

#endif