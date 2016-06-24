/*The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

  Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
       Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
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
  int rob(TreeNode* root) {
    if (root == nullptr) return 0;
    auto dp = dfs(root);
    return max(dp.first, dp.second);
  }
    
  //use a pair of int to store dp value dp.first means using the root
  //dp.second means don't use the node;
  // rob_root = max(rob_L + rob_R , no_rob_L + no_nob_R + root.val)
  // no_rob_root = rob_L + rob_R
  pair<int, int> dfs(TreeNode* node) {
    if (node == nullptr) return make_pair(0, 0);
    auto dp = make_pair(0, 0);
    auto dpL = dfs(node->left);
    auto dpR = dfs(node->right);
    dp.second = dpL.first + dpR.first;
    dp.first = max(dp.second, node->val + dpL.second + dpR.second);
    return dp;
  }
};
