#include <iostream>
#include "Hello.h"
using namespace std;

void HelloWorld()
{
    cout << endl << endl;
    Hello();
    World();
    cout << endl << endl;
    return;
}

void Hello()
{
    cout << "Hello";
    return;
}

void World()
{
    cout << "World";
    return;
}