/* Examples:
 * abbcdde -> ace
 * 
 * Approach:
 * * Stack
 * 1. iterate the string
 * 2. put the char into the stack
 * 3. if the char == the top element of the stack, then pop out
 * 4. continue
 * 5. pop all out from the stack into a string, and reverse it.
 */

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	string removeDuplicates(string s) {
		stack<char> st;
		string result = "";

		for (auto c : s) {
			if (!st.empty() && c == st.top()) {
				st.pop();
				continue;
			}

			st.push(c);
		}

		while(!st.empty()) {
			result += st.top();
			st.pop();
		}

		reverse(result.begin(), result.end());
	
		return result;
	}
};

int main() {
	Solution sol;
	string s = "abbcdde";
	string r;
	r = sol.removeDuplicates(s);
	for (auto i : r)
		cout << i;
	cout << endl;
}
