#include <stack>

class MyQueue {
private:
	std::stack<int> stackIn;
	std::stack<int> stackOut;
public:
	MyQueue () {}
	
	void push(int x)
	{
		stackIn.push(x);
	}

	int pop()
	{
		int result = peek();
		stackOut.pop();

		return result;
	}

	int peek()
	{
		if (stackOut.empty()) {
			while(!stackIn.empty()) {
				stackOut.push(stackIn.top());
				stackIn.pop();
			}
		}
		
		return stackOut.top();
	}

	bool empty()
	{
		if (!stackIn.empty() || !stackOut.empty())
			return false;
		return true;
	}
};
