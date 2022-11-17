#include <iostream>
#include <cassert>
#include <queue>

class MyStack {
private:
	std::queue<int> q;

public:
	MyStack() {}

	void push(int x)
	{
		q.push(x);
	}

	int pop()
	{
		assert(!q.empty());

		int size = q.size();
		size--;
		while(size--) {
			q.push(q.front());
			q.pop();
		}

		int result = q.front();
		q.pop();

		return result;
	}

	int top()
	{
		return q.back();
	}

	bool empty()
	{
		return q.empty();
	}
};
