# 232. Implement Queue using Stacks
[Implement Queue using Stacks - LeetCode](https://leetcode.com/problems/implement-queue-using-stacks/)

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

## Original
- Implementing with 2 stacks.

```cpp
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
```