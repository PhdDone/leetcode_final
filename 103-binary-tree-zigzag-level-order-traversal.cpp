/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;
    queue<TreeNode*> cur;
    queue<TreeNode*> next;
    bool leftToRight = true;
        
    cur.push(root);
    while(!cur.empty()) {
      vector<int> level;
      while(!cur.empty()) {  //two loops to check empty cur queue
	auto node = cur.front();
	cur.pop();
	level.push_back(node->val);
	if (node->left) next.push(node->left);
	if (node->right) next.push(node->right);
      }
      if (!leftToRight)
	reverse(level.begin(), level.end());
      res.push_back(level);
      leftToRight = !leftToRight;
      //cur = next;
      swap(cur, next); //use swap to CLEAN next!! otherwise next will include all the prev nodes;
    }
    return res;
  }
};
