/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//level order traverse, store the last element of each level
class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;
    queue<TreeNode*> cur;
    queue<TreeNode*> next;
    cur.push(root);
    while (!cur.empty()) {
      res.push_back(cur.back()->val);
      while (!cur.empty()) {
	auto curNode = cur.front();
	cur.pop();
	if (curNode->left) next.push(curNode->left);
	if (curNode->right) next.push(curNode->right);
      }
      swap(cur, next);
    }
    return res;
  }
};
