//Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

class Solution {
public:
  int closestValue(TreeNode* root, double target) {
    TreeNode* kid = root->val > target? root->left : root->right; //use the property of BST!!

    if (kid == nullptr) return root->val;
    int closest = closestValue(kid, target);
    return abs(target - root->val) > abs(target-closest)? closest : root->val;
  }
};

//https://segmentfault.com/a/1190000003797291
