# 226. Invert Binary Tree
[Invert Binary Tree - LeetCode](https://leetcode.com/problems/invert-binary-tree/)

Given the root of a binary tree, invert the tree, and return its root.

## DFS with Recursion
- Time: O(n)
- Space: O(logn)

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode *tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);

        return root;
    }
};
```