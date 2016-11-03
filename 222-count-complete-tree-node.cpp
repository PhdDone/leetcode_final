/*Given a complete binary tree, count the number of nodes.

  Definition of a complete binary tree from Wikipedia:
  In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/

//the last level may be not full, but are as far left as possible!!


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
  int countNodes(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    auto c = root;
    int hl = 0, hr = 0;
    while (c) {
      ++hl;
      c = c->left;
    }
    c = root;
    while (c) {
      ++hr;
      c = c->right;
    }
    if (hl == hr) return pow(2, hl) - 1; // if it's a full complete tree
    else return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
