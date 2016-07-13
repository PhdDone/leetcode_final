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
  void flatten(TreeNode* root) {
    if (root == nullptr) return;
    auto left = root->left;
    auto right = root->right;
    root -> left = root -> right = nullptr;
    flatten(left);
    flatten(right);
    root -> right = left;
    auto cur = root;
    while (cur -> right != nullptr) cur = cur -> right;
    cur->right = right;
  }
};
