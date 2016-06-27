/*Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

  For example:
  Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.



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
  int countUnivalSubtrees(TreeNode* root) {
    if (root == nullptr) return count;
    unival(root);
    return count;
  }
    
  bool unival(TreeNode* root) {
    if (root == nullptr)  { return true; }
    if (root->left == nullptr && root->right == nullptr) {
      ++count;
      cout << count << endl;
      return true;
    }
    bool isleft = unival(root->left);
    bool isright = unival(root->right);
    if (isleft && isright && ((root->left == nullptr) || (root->left->val == root -> val))
	&&((root->right == nullptr) || (root->right->val == root -> val))) {
      ++count;
      return true;
    }
    return false;
  }
private:
  int count = 0;
};
