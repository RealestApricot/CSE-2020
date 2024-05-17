// Vector20Main.cpp
// by KV for CSE 2020, Lab4 Feb 2024

#include <iostream>
#include <iomanip>
#include "Vector20.h"
using namespace std;

// printing values in a Vector20 object
void PrintVector20(Vector20<int>);

int main()
{
	Vector20<int> MyVector;

	for (int Index = 1; Index <= 25; Index++)
	{
		MyVector.PushBack(Index * 11); // entering 25 values into MyVector;
	}

	PrintVector20(MyVector); // showing contents of MyVector

	// asking for target index and how many times an erase is to happen
	// at this index; 

	int Target;
	int HowMany;
	int Value;
	cout << "Enter index of element to erase [0 - " << MyVector.VectorSize() - 1 << "]: ";
	cin >> Target;
	cout << endl;
	cout << "Erase at this index how many times [0 - " << MyVector.VectorSize() - Target << "]: ";
	cin >> HowMany;
	cout << endl;
	for (int i = 1; i <= HowMany; ++i)
	{
		MyVector.Erase(Target);
		PrintVector20(MyVector);
		cout << endl;
	}
	cout << endl;

	// asking for a target index and how many times value 999 is 
	// to be inserted at this index

	cout << "Enter index of element to insert 999 [0 - " << MyVector.VectorSize() - 1 << "]: "; 
	cin >> Target;
	cout << endl;
	cout << "Insert at this index how many times [0 - " << MyVector.VectorSize() - 1 << "]: ";
	cin >> HowMany;
	cout << endl;
	for (int i = 1; i <= HowMany; ++i)
	{
		MyVector.Insert(Target,999);
		PrintVector20(MyVector);
		cout << endl;
	}

	cout << "How many positions to move iterator to insertions point [0-24]: ";
	cin >> Target;
	cout << "Integer value to insert at this point: ";
	cin >> Value;
	cout << "Entering 3 random integers at 3 random indices: ";
	int RandomInteger1 = rand() % 1000;
	int RandomInteger2 = rand() % 1000;
	int RandomInteger3 = rand() % 1000;
	int RandomIndex1 = rand() % 25;
	int RandomIndex2 = rand() % 25;
	int RandomIndex3 = rand() % 25;
	MyVector.Insert(RandomInteger1, RandomIndex1);
	MyVector.Insert(RandomInteger2, RandomIndex2);
	MyVector.Insert(RandomInteger3, RandomIndex3);
	cout << "Inserted " << RandomInteger1 << " at index " << RandomIndex1 << endl;
	cout << "Inserted " << RandomInteger2 << " at index " << RandomIndex2 << endl;
	cout << "Inserted " << RandomInteger3 << " at index " << RandomIndex3 << endl;

	PrintVector20(MyVector);

	cout << "Erasing first, last, and middle elements with iterators ";
	Vector20<int>::Iterator First = MyVector.Begin();
	Vector20<int>::Iterator Middle = MyVector.Begin() + 12;
	Vector20<int>::Iterator Last = MyVector.End() - 1;
	MyVector.Erase(First);
	MyVector.Erase(Middle);
	MyVector.Erase(Last);
	cout << "Erasing " << *First << endl;
	cout << "Erasing " << *Middle << endl;
	cout << "Erasing " << *Last << endl;

	PrintVector20(MyVector);

	return 0;

}

	void PrintVector20(Vector20<int> Vector)
	{
		for (int Index = 0; Index < Vector.VectorSize(); ++Index)
			cout << Vector[Index] << " ";
		cout << endl << endl;
	}

