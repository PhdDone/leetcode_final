/*Given a binary tree, return all root-to-leaf paths.

  For example, given the following binary tree:

     1
   /   \
  2     3
   \
    5
  All root-to-leaf paths are:

  ["1->2->5", "1->3"]
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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    string path;
    if (root != nullptr)
      dfs(root, path + to_string(root->val), res);
    return res;
  }

  void dfs(TreeNode* root, string path, vector<string>& res) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
      res.push_back(path);
      return;
    }
    if (root->left != nullptr)
      dfs(root->left, path+"->"+to_string(root->left->val), res);
    if (root->right != nullptr)
      dfs(root->right, path+"->" + to_string(root->right->val), res);
  }
};
