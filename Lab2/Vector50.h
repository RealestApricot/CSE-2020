#ifndef VECTOR50_H
#define VECTOR50_H

#include <cassert>

using namespace std;

template <typename DataType>

class Vector50
{
    public:
        Vector50()
        {
            VectorData = new DataType[50];
            VectorSize = 50;
            VectorCapacity = 0;
        };

        Vector50(const Vector50& VectorToCopy)
        {
            VectorSize = VectorToCopy.VectorSize;
            VectorCapacity = VectorToCopy.VectorCapacity;
            VectorData = nullptr;

            for (int Index = 0; Index < VectorSize; Index++)
            {
                VectorData[Index] = VectorToCopy.VectorData[Index];
            }
        };


        Vector50& operator= (const Vector50& VectorToCopy)
        {
            for (int Index = 0; Index < VectorSize; Index++)
            {
                VectorData[Index] = VectorToCopy[Index];
            }

            return *this;
        };

        ~Vector50()
        {
            delete[] VectorData;
        }

        bool Empty() const
        {
            return VectorSize == 0;
        }

        int Size() const
        {
            return VectorSize;
        }

        int Capacity() const
        {
            return VectorCapacity;
        }

        DataType& operator[] (int Index)
        {
            assert(Index >= 0 && Index < VectorSize);
            return VectorData[Index];
        }

        void Pushback(const DataType& Value)
        {
            if (VectorSize < VectorCapacity)
            {
                VectorData[VectorSize] = Value;
                VectorSize++;
            }
            else
            {
                //do nothing for now
            }
        }

    private:
        int VectorSize;
        int VectorCapacity;
        DataType* VectorData;
};

#endif