# 104. Maximum Depth of Binary Tree
[Maximum Depth of Binary Tree - LeetCode](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

## DFS
- Time Complexity = O(n)
- Space Complexity = O(logn)

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
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        
        int max_depth = 0;
        queue<TreeNode*> q({root});
        
        while(!q.empty()) {
            max_depth++;
            
            for (int i = q.size(); i > 0; i--) {
                TreeNode *node = q.front();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }
        }
        
        return max_depth;
    }
};
```
### Optimal
```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
```

## BFS
- Time Complexity = O(n)
- Space Complexity = O(logn)

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        
        int max_depth = 0;
        queue<TreeNode*> q({root});
        
        while(!q.empty()) {
            max_depth++;
            
            for (int i = q.size(); i > 0; i--) {
                TreeNode *node = q.front();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }
        }
        
        return max_depth;
    }
};
```

## References
https://www.youtube.com/watch?v=hTM3phVI6YQ