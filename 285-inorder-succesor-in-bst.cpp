/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

  Note: If the given node has no in-order successor in the tree, return null.
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
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (p->right) {
      return leftMostNode(p->right); //if has right child, left most of right child is the result
    }
    //do a binary search
    TreeNode* cur = root;
    TreeNode* succ = nullptr;
    while(cur != p) {
      if (cur->val < p->val) {
        cur = cur->right;
      } else { //find the nearest node that has a larger value than p->val
        succ = cur;
        cur = cur->left;
      }
    }
    return succ;
  }

  TreeNode* leftMostNode(TreeNode* node) {
    while (node->left) {
      node = node->left;
    }
    return node;
  }
};
