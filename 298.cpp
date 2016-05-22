/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
 */

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
  int longestConsecutive(TreeNode* root) {
    return helper(root, nullptr, 0);
  }
    
  int helper(TreeNode* now, TreeNode* parent, int len) {
    if (now == nullptr)
      return len;
    if (parent && (parent->val + 1) == now -> val)
      len += 1;
    else
      len = 1;
    return max(len, max(helper(now->left, now, len), helper(now->right, now, len)));
  }
};
