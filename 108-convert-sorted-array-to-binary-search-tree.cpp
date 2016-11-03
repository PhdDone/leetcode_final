//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    int N = nums.size();
    return buildBST(nums, 0, N-1);
  }

  TreeNode* buildBST(const vector<int>& nums, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    if (start == end) return new TreeNode(nums[start]);

    int mid = start + ((end - start) >> 1);
    //cout << start << " " << end << endl;
    TreeNode* res = new TreeNode(nums[mid]);
    res->left = buildBST(nums, start, mid - 1);
    res->right = buildBST(nums, mid + 1, end);
    return res;
  }
};
