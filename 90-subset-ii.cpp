class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    sort(nums.begin(), nums.end());
    dfs(nums, 0, res, path);
    return res;
  }

  void dfs(const vector<int>& nums, int step, vector<vector<int>>& res, vector<int>& path) {
    /*if (step == nums.size()) {
            retur;n
            }*/
    res.push_back(path);
    int N = nums.size();
    for (int i = step; i < N; ++i) {
      if (i != step && nums[i] == nums[i-1]) continue; // check if current i is used
      path.push_back(nums[i]);
      dfs(nums, i+1, res, path); //i + 1, not step + 1
      path.pop_back();
    }
  }
};
