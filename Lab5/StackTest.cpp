#include <iostream>
#include <map>
#include "Vector.h"
#include "Stack.h"

using namespace std;

// Function declaration
void CheckBrackets(string Expression, map<char, char> RightBrackets, map<char, char> LeftBrackets);

int main()
{	
	Stack<Vector<char>> MyStack;
	for (int Index = 0; Index < 10; Index++)
	{
		cout << "Pushing into stack: " << Index << endl;
		MyStack.Push(Index);
	}

	cout << endl << endl;
	cout << "Popping the stack one element at a time ..." << endl << endl;
	while (!MyStack.Empty())
	{
		int TopValue = MyStack.Top();
		cout << TopValue << " ";
		MyStack.Pop();
	}

	cout << endl << endl;
	
	
	map<char, char> RightBrackets = {
	    {'(', ')'},
	    {'{', '}'},
	    {'[', ']'}};

	map<char, char> LeftBrackets = {
	    {')', '('},
	    {'}', '{'},
	    {']', '['}};

	//Ask for user input
	bool Finished = false;
	while (Finished == false)
	{
		cout << "Enter an Expression: ";
		string Expression;
		cin >> Expression;
		// Call the CheckBrackets function
		CheckBrackets(Expression, RightBrackets, LeftBrackets);

		cout << "Do you want to enter another expression? (y/n): ";
		char Response;
		cin >> Response;
		if (Response == 'n')
		{
			Finished = true;
		}
	}

	return 0;
}

// Function definition
void CheckBrackets(string Expression, map<char, char> RightBrackets, map<char, char> LeftBrackets)
{
	Stack<Vector<char>> MyCharStack;

	for (char Character : Expression)
	{
		if (RightBrackets.count(Character) > 0)
		{
			MyCharStack.Push(Character);
		}
		else if (LeftBrackets.count(Character) > 0)
		{
			if (MyCharStack.Empty())
			{
				cout << "Mismatched brackets" << endl;
				return; // Remove return 0;
			}
			else if (MyCharStack.Top() == LeftBrackets[Character])
			{
				MyCharStack.Pop();
			}
			else
			{
				cout << "Mismatched brackets" << endl;
				return; // Remove return 0;
			}
		}
	}

	if (MyCharStack.Empty())
	{
		cout << "Matching brackets" << endl;
	}
	else
	{
		cout << "Mismatched brackets" << endl;
	}
}
