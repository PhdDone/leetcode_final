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
  bool isValidBST(TreeNode* root) {
    if (root==nullptr) return true;
    long maxVal = LONG_MAX; //use LONG_MAX instead of INT_MAX because INT_MAX could be the node value
    long minVal = LONG_MIN;
    return isValidBST(root->right, root->val, maxVal) && isValidBST(root->left, minVal, root->val);
  }

  bool isValidBST(TreeNode* node, long minVal, long maxVal) {
    if (node == nullptr) return true;
    if (node->val > minVal && node->val < maxVal) {
      //cout << node->val << endl;
      return isValidBST(node->right, node->val, maxVal) && isValidBST(node->left, minVal, node->val);
    } else {
      return false;
    }
  }
};
