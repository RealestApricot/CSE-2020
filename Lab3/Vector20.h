// Still a Simple Basic Vector Data Structure, but
// KV, Feb 2024

#ifndef VECTOR20_H
#define VECTOR20_H

#include <iostream>
#include <cassert>  

using namespace std;


template <typename DataType>
class Vector20
{
public:
	Vector20()
	{
		Size = 0;
		Capacity = 20;
		Data = new DataType[Capacity];
	
	}

	Vector20(const Vector20& VectorToCopy)
	{
		Size = VectorToCopy.Size;
		Capacity = VectorToCopy.Capacity;
		Data = new DataType[Capacity];
		for (int i = 0; i < Size; i++)
		{
			Data[i] = VectorToCopy.Data[i];
		}
	
	}

	typedef DataType* Iterator;
	typedef const DataType* ConstIterator;

	Iterator Begin()
	{
		return &Data[0];
	}

	Iterator End()
	{
		return &Data[VectorSize()];
	}

	Vector20& operator= (const Vector20& VectorToCopy)
	{
		for (int Index = 0; Index < Size; Index++)
			Data[Index] = VectorToCopy.Data[Index];
		return *this;
	}
	
	~Vector20()
	{
		delete[] Data;
	}

	bool IsEmpty() const
	{
		return Size == 0;
	}
	int VectorSize() const
	{
		return Size;
	}

	int VectorCapacity() const
	{
		return Capacity;
	}

	DataType& operator[](int Index)
	{
		assert(Index >= 0 && Index < Size);
		return Data[Index];
	}

	DataType& Back() const
	{
		return Data[Size - 1];
	}

	DataType& Front() const
	{
		return Data[0];
	}

	void PushBack(const DataType& DataToAdd)
	{
		if (Size < Capacity)
		{
			//cout << "within capacity ..." << endl;
			Data[Size] = DataToAdd;
			Size++;
		}
		else
		{
			//cout << "EXPAND capacity ..." << endl;
			DataType* MoreData = new DataType[Capacity * 2 + 1];
			for (int Index = 0; Index < Size; ++Index)
			{
				MoreData[Index] = std::move(Data[Index]);
			}
			std::swap(Data, MoreData);
			delete[] MoreData;
			Capacity = Capacity * 2 + 1;

			Data[Size] = DataToAdd;
			Size++;
		}
	}

	void PopBack()
	{
		--Size;
	}

	void Erase(int Index)
	{
		assert(Index >= 0 && Index < Size);
		if (Index < Size - 1)
		{
			PopBack();
			return;
		}
		for (int i = Index + 1; i < Size; ++i)
		{
			Data[i - 1] = Data[i];
		}
		PopBack();
		return;
	}

	void Erase(Iterator Position)
	{
		assert(Position >= Begin() && Position < End());
		if (Position == End() - 1)
		{
			PopBack();
			return;
		}
		Iterator Position1 = Position + 1;
		Iterator Position2 = Position;
		while (Position1 < End())
		{
			*Position2 = *Position1;
			Position1++;
			Position2++;
		}
		return;
	}

	void Insert(int Index, int Value)
	{
		// to be filled for Lab4
		PushBack(Back());

		for (int i = Size - 2; i >= Index; --i)
		{
			Data[i + 1] = Data[i];
		}

		Data[Index] = Value;
	}

	void Insert(Iterator Position, int Value)
	{
		if (Position == End())
		{
			PushBack(Value);
			return;
		}
		assert(Position >= Begin() && Position <= End());
		PushBack(Back());
		Iterator Position1 = End() - 1;
		Iterator Position2 = End() - 2;
		while (Position1 >= Position)
		{
			*Position2 = *Position1;
			Position1--;
			Position2--;
		}
		*Position = Value;
		return;
	}
	

private:
	int Size;
	int Capacity;
	DataType* Data;
};

#endif