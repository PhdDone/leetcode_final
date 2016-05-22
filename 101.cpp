/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).*/




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
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    return isSymmetric(root->left, root->right);
  }
    
  bool isSymmetric(const TreeNode* left, const TreeNode* right) {
    if (left == nullptr)
      return right == nullptr;
    if (right == nullptr)
      return left == nullptr;
    if (left->val != right->val)
      return false;
    if (!isSymmetric(left->left, right->right))
      return false;
    if (!isSymmetric(left->right, right->left))
      return false;
    return true;
  }
};


// wrong solution, simple inorder won't work for [1,2,3,3,null,2,null]
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
  bool isSymmetric(TreeNode* root) {
    vector<int> vals;
    inOrder(root, vals);
    vector<int> rVals = vals;
    reverse(vals.begin(), vals.end());
    return vals == rVals;
  }
    
  void inOrder(const TreeNode* node, vector<int>& vals) {
    if (node == nullptr) return;
        
    inOrder(node->left, vals);
    vals.push_back(node->val);
    inOrder(node->right, vals);
  }
};
