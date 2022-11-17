/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// use dummy head
// iterate the whole list
// move target & current pointers until the current pointer becomes NULL, and target pointer is n steps slower than target pointer

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* curNode = dummyHead;
		ListNode* prevNode = dummyHead;

		while(curNode != nullptr && curNode->next != nullptr) {
			curNode = curNode->next;
		
			if (n == 0) {
				prevNode  = prevNode ->next;
			} else {
				n--;
			}
		}

		ListNode* tmpNode = prevNode ->next;
		prevNode ->next = tmpNode->next;
		delete tmpNode;

		return dummyHead->next;
    }
};
