/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.
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
  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (root == nullptr) return vector<vector<int>>{};
        
    map<int, vector<int>> results;
    queue<pair<int, TreeNode*>> q;
    q.push(pair<int, TreeNode*>{0, root});
    return helper(results, q);
  }
    
  vector<vector<int>> helper(map<int, vector<int>>& results, queue<pair<int, TreeNode*>> q) {
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      results[node.first].push_back(node.second->val);
      if (node.second->left) {
	q.push(pair<int, TreeNode*>{node.first-1, node.second->left});
      }
      if (node.second->right) {
	q.push(pair<int, TreeNode*>{node.first+1, node.second->right});
      }
    }
    vector<vector<int>> res;
    for (auto i = results.begin(); i != results.end(); ++i) {
      res.push_back(i->second);
    }
    return res;
  }
};
