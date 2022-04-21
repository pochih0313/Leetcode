#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int main()
{
	ListNode *node = new ListNode(6);
	std::cout << node->val << std::endl;
}
