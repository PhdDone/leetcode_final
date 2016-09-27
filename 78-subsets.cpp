/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    int N = nums.size();
    if (N == 0) return res;
    int cur = 0;
    vector<int> path;
    dfs(nums, cur, path, res);
    return res;
  }

  void dfs(const vector<int>& nums, int cur, vector<int>&path, vector<vector<int>>& res) {
    int N = nums.size();
    if (N == cur) {
      res.push_back(path);
      return;
    } else {
      dfs(nums, cur + 1, path, res);
      path.push_back(nums[cur]);
      dfs(nums, cur + 1, path, res);
      path.pop_back();
    }
  }
};
