/*Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
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

//http://bangbingsyb.blogspot.com/2014/11/leetcode-binary-tree-level-order.html
class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> results;
    if (root == nullptr) return results;
        
    queue<TreeNode*> curQ;
    queue<TreeNode*> nextQ;
    curQ.push(root);
    vector<int> result;
    while(!curQ.empty()) {
      auto curNode = curQ.front();
      curQ.pop();
      if (curNode->left) nextQ.push(curNode->left);
      if (curNode->right) nextQ.push(curNode->right);
      result.push_back(curNode->val);
      if (curQ.empty()) {
	curQ = nextQ;
	nextQ = queue<TreeNode*>{};
	results.push_back(result);
	result = vector<int>{};
      }
    }
    reverse(results.begin(), results.end());
    return results;
  }
};
