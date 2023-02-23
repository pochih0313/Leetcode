# 235. Lowest Common Ancestor of a Binary Search Tree
[Lowest Common Ancestor of a Binary Search Tree - LeetCode](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

## Recursion
- Find the value between the values of two given nodes. 
- Time: O(logn) = O(the height of the tree)
- Space: O(logn)

```cpp
/**
 * Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

class Solution {
public:    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        return root;
    }
};
```
```cpp
class Solution {
public:    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        
        if (max(p->val, q->val) < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (min(p->val, q->val) > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        return root;
    }
};
```
    
## Iteration
- Time: O(logn)
- Space: O(1)
    
```cpp
class Solution {
public:    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if (max(p->val, q->val) < root->val) {
                root = root->left;
            } else if (min(p->val, q->val) > root->val) {
                root = root->right;
            } else {
                return root; 
            }   
        }
        
        return NULL;
    }
};
```