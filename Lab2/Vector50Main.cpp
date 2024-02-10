#include <iostream>
#include "Vector50.h"
using namespace std;

int main()
{
    Vector50<int> my25;
    cout << my25.Capacity() << endl;
    for (int Index = 0; Index < 25; Index++)
    {
        my25[Index] = Index;
        cout << my25[Index] << endl;
    }

    return 0;
}