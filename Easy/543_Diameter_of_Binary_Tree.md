# 543. Diameter of Binary Tree
[Diameter of Binary Tree - LeetCode](https://leetcode.com/problems/diameter-of-binary-tree/)

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

## DFS
- Use depth first searching (DFS) to get the height of every node, and then compare the maximum length (the height of the left tree + the height of the right tree) when backtracking.

- Time Complexity: O(n)
- Space Complexity: O(logn)

```cpp
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
private:
    int max_length = 0;
public:
    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left_h = dfs(node->left);
        int right_h = dfs(node->right);
        
        max_length = max(max_length, left_h + right_h);
        return 1 + max(left_h, right_h);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root->left && !root->right) return 0;
        
        dfs(root);
        
        return max_length;
    }
};
```