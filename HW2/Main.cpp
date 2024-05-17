// postfix calculator; simple case with operands that can
// only be single characters or single digits, no white space;
// Kerstin Voigt, CSE 2020  Spring 2023; Lab 7
#include "Postfix.h"
#include "Vector.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Vector<string> postfixes;
	postfixes.push_back("8 3 -");
	postfixes.push_back("15 8 3 - /");
	postfixes.push_back("15 8 3 - / 12 7 3 + * +");
	postfixes.push_back("3 5 4 * 2 1 - 6 + 9 - / +");

	for (int i = 0; i < postfixes.size(); i++)
	{
		int result = eval_postfix(postfixes[i]);
		cout << "The result of " << postfixes[i] << " is " << result << endl;
		cout << "---------------------------------------------" << endl;
	}

	return 0;
}
