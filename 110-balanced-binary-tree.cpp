/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
*/
class Solution {
public:
  bool isBalanced(TreeNode* root) {
    if (findDepth(root) == -1) return false;
    return true;
  }

  int findDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = findDepth(root->left);
    if (left == -1) return -1;

    int right = findDepth(root->right);
    if (right == -1) return -1;

    if (abs(left - right) > 1) return -1;
    return max(left, right) + 1;
  }
};
