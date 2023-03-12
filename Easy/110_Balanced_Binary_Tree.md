# 110. Balanced Binary Tree
[Balanced Binary Tree - LeetCode](https://leetcode.com/problems/balanced-binary-tree/)

Given a binary tree, determine if it is height-balanced.

## DFS
- Using DFS to calculate the height of the child tree from the root. Determine if the left and the right trees are balanced, if not, return -1. When backtracking, if -1 exists, then return -1.
- Time: O(N)
- Space: O(logN)

```cpp
class Solution {
public:
    int getHeight(TreeNode* node) {
        if (!node) return 0;
        
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        
        if (left == -1 || right == -1 || abs(left-right) > 1) return -1;
        
        return 1 + max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        
        if (getHeight(root) == -1) return false;
        
        return true;
    }
};
```

* Cleaner
    ```cpp
    class Solution {
    public:
        int getHeight(TreeNode* root) {
            if (!root)
                return 0;

            int lh = getHeight(root->left);
            if (lh == -1)
                return -1;

            int rh = getHeight(root->right);
            if (rh == -1)
                return -1;

            if (abs(lh - rh) > 1)
                return -1;

            return 1 + max(lh, rh);
        }

        bool isBalanced(TreeNode* root) {
            if (!root)
                return true;

            return getHeight(root) != -1;
        }
    };
    ```