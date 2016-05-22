/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
  int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    //remember to check there's no right but only left child and vice versa!
    if (root->left && !root->right) return minDepth(root->left) + 1;
    if (root->right && !root->left) return minDepth(root->right) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
  }
};
