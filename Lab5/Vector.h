// Adopted from M.A. Weiss, DSAAC++ textbook
// by KV, Feb 2024
#ifndef VECTOR_H
#define VECTOR_H
#include <cstdlib>
#include <iostream>
#include <cassert> // KV prefers assert ...
template <typename DataType>
class Vector
{
public:
	typedef DataType ValueType;
	
	explicit Vector(int initSize = 0)
	    : theSize{initSize}, theCapacity{initSize + SPARE_CAPACITY}
	{
		data = new DataType[theCapacity];
	}
	Vector(int initSize, int initValue)
	    : theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
	{
		data = new DataType[theCapacity];
		for (int i = 0; i < theCapacity; i++)
			data[i] = initValue;
	}
	Vector(const Vector &rhs)
	    : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, data{nullptr}
	{
		data = new DataType[theCapacity];
		for (int k = 0; k < theSize; ++k)
			data[k] = rhs.data[k];
	}
	Vector &operator=(const Vector &rhs)
	{
		Vector copy = rhs;
		std::swap(*this, copy);
		return *this;
	}
	~Vector()
	{
		delete[] data;
	}
	Vector(Vector &&rhs)
	    : theSize{rhs.theSize}, theCapacity{rhs.theCapacity},
	      data{rhs.data}
	{
		rhs.data = nullptr;
		rhs.theSize = 0;
		rhs.theCapacity = 0;
	}
	Vector &operator=(Vector &&rhs)
	{
		std::swap(theSize, rhs.theSize);
		std::swap(theCapacity, rhs.theCapacity);
		std::swap(data, rhs.data);
		return *this;
	}
	bool empty() const
	{
		return size() == 0;
	}
	int size() const
	{
		return theSize;
	}
	int capacity() const
	{
		return theCapacity;
	}
	DataType &operator[](int index)
	{
		assert(index >= 0 && index < theSize);
		return data[index];
	}
	const DataType &operator[](int index) const
	{
		assert(index >= 0 && index < theSize);
		return data[index];
	}
	void resize(int newSize)
	{
		if (newSize > theCapacity)
			reserve(newSize * 2);
		theSize = newSize;
	}
	void reserve(int newCapacity)
	{
		if (newCapacity < theSize)
			return;
		DataType *newArray = new DataType[newCapacity];
		for (int k = 0; k < theSize; ++k)
			newArray[k] = std::move(data[k]);
		theCapacity = newCapacity;
		std::swap(data, newArray);
		delete[] newArray;
	}
	void push_back(const DataType &x)
	{
		if (theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		data[theSize++] = x;
	}
	void push_back(DataType &&x)
	{
		if (theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		data[theSize++] = std::move(x);
	}
	void pop_back()
	{
		assert(theSize >= 1);
		--theSize;
	}
	const DataType &back() const
	{
		assert(theSize >= 1);
		return data[theSize - 1];
	}
	// Iterators (new concept)
	typedef DataType *iterator;
	typedef const DataType *const_iterator;
	iterator begin()
	{
		return &data[0];
	}
	const_iterator begin() const
	{
		return &data[0];
	}
	iterator end()
	{
		return &data[size()];
	}
	const_iterator end() const
	{
		return &data[size()];
	}
	void erase(int index)
	{
		assert(index >= 0 && index < theSize);
		if (index == theSize - 1)
		{
			pop_back();
			return;
		}
		for (int i = index; i < theSize; i++)
			data[i] = data[i + 1];
		pop_back();
		return;
	}
	void erase(iterator itr)
	{
		assert(itr >= begin() && itr < end());
		if (itr == &data[theSize - 1])
		{
			pop_back();
			return;
		}
		iterator itr1 = itr;
		iterator itr2 = itr + 1;
		while (itr2 != end())
		{
			*itr1 = *itr2;
			++itr1;
			++itr2;
		}
		pop_back();
		return;
	}
	void insert(int index, int value)
	{
		if (index == theSize)
		{
			push_back(value);
			return;
		}
		assert(index >= 0 && index < theSize);
		push_back(back());
		for (int i = theSize; i >= index; i--)
			data[i] = data[i - 1];
		data[index] = value;
		return;
	}
	void insert(iterator itr, int value)
	{
		if (itr == end())
		{
			push_back(value);
			return;
		}
		assert(itr >= begin() && itr < end());
		push_back(back());
		iterator itr1 = end() - 2;
		iterator itr2 = end() - 1;
		while (itr1 >= itr)
		{
			*itr2 = *itr1;
			itr1--;
			itr2--;
		}
		*itr = value;
		return;
	}
	static const int SPARE_CAPACITY = 2;

private:
	int theSize;
	int theCapacity;
	DataType *data;
};
#endif