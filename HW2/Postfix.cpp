#include "Postfix.h"
#include "Vector.h"
#include "Stack.h"
#include <sstream>
#include <cassert>
#include <cctype>
#include <iostream>
#include <map>

using namespace std;

//Create a map of operator symbols to their corresponding functions
int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return x / y; }

const map<string, int (*)(int, int)> OPERATORS = {
    {"+", add},
    {"-", subtract},
    {"*", multiply},
    {"/", divide}};

// returns integer result of evaluation
// of string postfix expression

int eval_postfix(string postfix)
{
	Stack<Vector<int>> stack;
	string next;
	int num;
	int result;

	istringstream istrm(postfix);
	istrm >> next;

	while (!istrm.fail())
	{
		if (isalnum(next[0]))
		{
			num = stringToInt(next);
			stack.Push(num);
			cout << "push onto stack" << endl
			     << endl;
		}
		else
		{
			assert(is_operator(next));
			cout << "operator " << next << " to be applied ..." << endl
			     << endl;
			int x2 = stack.Top();
			stack.Pop();
			cout << "... pop " << x2 << endl
			     << endl;

			int x1 = stack.Top();
			stack.Pop();
			cout << "... pop " << x1 << endl
			     << endl;

			result = apply_op(next, x1, x2);
			stack.Push(result);
			cout << " --> push " << result << " onto stack" << endl
			     << endl;
		}
		istrm >> next;
	}
	assert(stack.Size() == 1);
	result = stack.Top();
	stack.Pop();

	return result;
}

// converts string of digits to integer value
int stringToInt(string x)
{
	int num;
	stringstream(x) >> num;
	return num;
}

// true when string is an operator symbol
bool is_operator(string x)
{
	// Check if the operator exists in the map
	return OPERATORS.count(x) > 0;
}

// returns value after operator op applied to 
// int operands x and y
int apply_op(string op, int x, int y)
{
	// COMPLETE IN LAB7
	return OPERATORS.at(op)(x, y);
}
