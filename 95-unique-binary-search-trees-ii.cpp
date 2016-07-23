/*Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

     1         3     3      2      1
      \       /     /      / \      \
       3     2     1      1   3      2
      /     /       \                 \
     2     1         2                 3
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
  vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> res;
    if (n == 0) return res; // check null
    dfs(1, n, res);
    return res;
  }

  void dfs(int start, int end, vector<TreeNode*>& res) {
    if (start > end) res.push_back(nullptr);
    for (int i = start; i <= end; ++i) {
      vector<TreeNode*> leftTrees;
      dfs(start, i-1, leftTrees);
      vector<TreeNode*> rightTrees;
      dfs(i+1, end, rightTrees);

      for (auto left : leftTrees) {
        for (auto right : rightTrees) {
          TreeNode* root = new TreeNode(i);
          root->left = left;
          root->right = right;
          res.push_back(root);
        }
      }
    }
  }
};
