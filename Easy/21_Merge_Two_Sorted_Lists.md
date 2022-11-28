# 21. Merge Two Sorted Lists
[Merge Two Sorted Lists - LeetCode](https://leetcode.com/problems/merge-two-sorted-lists/)

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

## Iterative
- Iterate two lists until there is one list finished.
- link the remaining of the other list to the result list.

```cpp
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
class Solution {
public:
    void insert(ListNode*& cur_node, int value) {
        cur_node->next = new ListNode(value);
        cur_node = cur_node->next;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return nullptr;
        if (!list1) return list2;
        else if (!list2) return list1;
        
        ListNode* dummy_node = new ListNode();
        ListNode* cur_node = dummy_node;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        
        while(p1 && p2) {
            if (p1->val <= p2->val) {
                insert(cur_node, p1->val);
                p1 = p1->next;
                
            } else {
                insert(cur_node, p2->val);
                p2 = p2->next;
            }
        }
        
        if (p1 && !p2) cur_node->next = p1;
        else if (p2 && !p1) cur_node->next = p2;
        
        return dummy_node->next;
    }
};
```

### Optimal
- Simplify the code for the final linking of the remaining nodes.

```cpp
cur_node->next = (p1 ? p1 : p2);
```

## Recursive
```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
```

### Optimal
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode *head = l1->val < l2->val ? l1 : l2;
    ListNode *nonhead = l1->val < l2->val ? l2 : l1;
    head->next = mergeTwoLists(head->next, nonhead);
    return head;
}
```