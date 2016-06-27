/*
Given a binary tree, find all leaves and then remove those leaves. Then repeat the previous steps until the tree is empty.

  Example:
Given binary tree 
          1
         / \
        2   3
       / \     
      4   5    
  Returns [4, 5, 3], [2], [1].

  Explanation:
  1. Remove the leaves [4, 5, 3] from the tree

          1
         / 
        2          
2. Remove the leaf [2] from the tree

          1          
3. Remove the leaf [1] from the tree

          []         
  Returns [4, 5, 3], [2], [1].
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
  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> results;
    vector<int> leaves;
    while (root) {
      removeLeaves(&root, leaves);
      results.push_back(leaves);
      leaves = vector<int>{};
    }
    return results;
  }
    
  void removeLeaves(TreeNode** node, vector<int>& leaves) {
    if ((*node)->left == nullptr && (*node)->right == nullptr) {
      leaves.push_back((*node)->val);
      *node = nullptr;
      return;
    }
    if ((*node)->left) removeLeaves(&(*node)->left, leaves);
    if ((*node)->right) removeLeaves(&(*node)->right, leaves);
  }
};
