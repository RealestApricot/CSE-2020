#ifndef POSTFIX_H_
#define POSTFIX_H_

#include <string>

using namespace std;

int eval_postfix(string postfix);
bool is_operator(string s);
int stringToInt(string s);
int apply_op(string op, int a, int b);

#endif

