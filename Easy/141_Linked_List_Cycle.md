# 141. Linked List Cycle
[Linked List Cycle - LeetCode](https://leetcode.com/problems/linked-list-cycle/description/)

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

## Hash Set (Original)
- Use hash set to record the traversed nodes. While traversing the linked list, if the node is in the set, returning true (having a cycle).
- Time Complexity = O(n)
- Space Complexity = O(n)

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        
        ListNode *cur_node = head;
        unordered_set<ListNode*> node_set;
        while(cur_node) {
            auto it = node_set.find(cur_node);
            if (it != node_set.end()) return true;
            
            node_set.insert(cur_node);
            cur_node = cur_node->next;
        }
        return false;
    }
};
```

## 2 Pointers
- Using two pointers to traverse the linked list. The slow pointer move 1 step and the fast one move 2 step. If there is a cycle, the fast pointer will run into the slow one.
- Time Complexity = O(n)
- Space Complexity = O(1)


```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        
        ListNode *fast = head, *slow = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) return true;
        }
        return false;
    }
};
```

### Optimal
- if the next node of the head node is nullptr, then return false at first.

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;

        ListNode *f_node = head->next->next, *s_node = head->next;
        while(f_node != nullptr && f_node->next != nullptr) {
            if (f_node == s_node) return true;
            
            f_node = f_node->next->next;
            s_node = s_node->next;
        }
        return false;
    }
};
```