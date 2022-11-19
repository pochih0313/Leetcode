# 876. Middle of the Linked List
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

## Brute Force
- 1st iteration: Get the size of the linked list.
- 2nd iteration: Walk to the middle position (size/2+1) and return.

- T: O(n)
- S: O(1)

## Two Pointers
- Iterate the linked list only once
  - Move the slow pointer 1 step, while move the fast pointer 2 steps. When the fast pointer or the next node of the fast poiner is NULL, break the loop.
  - Return the node of the slow pointer.

- T: O(n)
- T: O(1)

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head->next) return head;

        ListNode *fast = head, *slow = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
```

