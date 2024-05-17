#include "List.h"
#include "Vector-1.h"

using namespace std;

template <typename DataType>
int LinearSearch(const Vector<DataType> VectorToSearch, const DataType& Target)
{
	for (int i = 0; i < VectorToSearch.size(); i++)
	{
		if (VectorToSearch[i] == Target)
		{
			return i;
		}
	}
	return -1;
};

template <typename DataType>
typename List<DataType>::const_iterator LinearSearch(const List<DataType>& ListToSearch, const DataType& Target)
{
	typename List<DataType>::const_iterator itr;
	for (itr = ListToSearch.begin(); itr != ListToSearch.end(); ++itr)
	{
		if (*itr == Target)
		{
			return itr;
		}
	}
	return ListToSearch.end();
};

template <typename DataType>
int RecursiveLinearSearch(int index, const Vector<DataType> VectorToSearch, const DataType& Target)
{
	if (VectorToSearch.empty() || index >= VectorToSearch.size())
	{
		return -1;
	}
	if (VectorToSearch[index] == Target)
	{
		return index;
	}
	return RecursiveLinearSearch(index + 1, VectorToSearch, Target);
};


template <typename DataType>
typename List<DataType>::const_iterator RecursiveLinearSearch(typename List<DataType>::const_iterator itr, const List<DataType>& ListToSearch, const DataType& Target)
{
	if (itr == ListToSearch.end())
	{
		return ListToSearch.end();
	}
	if (*itr == Target)
	{
		return itr;
	}
	return RecursiveLinearSearch(++itr, ListToSearch, Target);
};