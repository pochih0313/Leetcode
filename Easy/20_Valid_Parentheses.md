# 20. Valid Parentheses
[Valid Parentheses - LeetCode](https://leetcode.com/problems/valid-parentheses/)

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

## Stack
- Approach
    - iterate the string
    - if the character is left bracket, put it into the stack
    - if the character is right bracket, then
	check whether the top item in the stack is the correspoding left bracket
        - yes: pop the item and continue
        - no: return invalid
    - when finish iterating the string, check if the stack is empty or not
        - yes: return valid
	    - no: return invalid
- Remember to check if the stack is empty or not before calling stack.top().

```cpp
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
```