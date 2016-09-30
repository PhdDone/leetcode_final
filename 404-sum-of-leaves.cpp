/*Find the sum of all left leaves in a given binary tree.

Example:

    3
       / \
      9  20
        /  \
       15   7

    There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
      Show Company Tags
      Show Tags
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
  int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr) return 0;
    int res = 0;
    dfs(root, res);
    return res;
  }

  void dfs(TreeNode* node, int& res) {
    if (node == nullptr) return;
    // check a node's left child is a leaf or not
    if (node->left && node->left->left == nullptr && node->left->right == nullptr) {
      res += node->left->val;
      dfs(node->right, res);
    } else {
      dfs(node->left, res);
      dfs(node->right, res);
    }
  }
};
