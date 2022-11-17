/*
Examples:
({[]}): valid
({)}: invalid

Approach:
stack

1. iterate the string
2. if the character is left bracket, put into the stack
3. if the character is right bracket, then
	check whether the top item in the stack is the correspoding left bracket
	yes: pop the item and continue
	no: return invalid
4. when finish iterating the string, check if the stack is empty or not,
	yes: return valid
	no: return invalid
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		std::stack<char> check_stack;
		for (char c : s) {
			if (c == '(')
				check_stack.push(')');
			else if (c == '{')
				check_stack.push('}');
			else if (c == '[')
				check_stack.push(']');
			else if (check_stack.empty() || check_stack.top() != c)
				return false;
			else
				check_stack.pop();
		}

		if (!check_stack.empty())
			return false;
		return true;
	}
};

int main()
{
	Solution sol;
	string s = "{}[";
	cout << sol.isValid(s) << endl;
}
