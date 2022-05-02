#include <queue>

class MyStack {
private:
	std::queue<int> q1;
	std::queue<int> q2;

public:
	MyStack() {}

	void push(int x)
	{
		q1.push(x);
	}

	int pop()
	{
		assert(!q1.empty());

		int result;
		while(!q1.empty()) {
			result  = q1.front();
			q1.pop();
			if (!q1.empty())
				q2.push(result);
		}
		while(!q2.empty()) {
			q1.push(q2.front());
			q2.pop();
		}

		return result;
	}

	int top()
	{
		return q1.back();
	}

	bool empty()
	{
		return q1.empty();
	}
};
