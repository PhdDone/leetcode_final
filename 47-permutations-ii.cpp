/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

  For example,
  [1,1,2] have the following unique permutations:
  [1,1,2], [1,2,1], and [2,1,1].
*/


class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> results;
    vector<bool> visited(nums.size(), false);
    sort(nums.begin(), nums.end());
    int step = 0;
    vector<int> path;
    DFS(nums, results, path, step, visited);
    return results;
  }
    
  void DFS(vector<int> const& nums, vector<vector<int>>& results, vector<int>& path, int step, vector<bool> visited) {
    if (step == nums.size()) {
      results.push_back(path);
      return;
    }
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (visited[i] == 0) {
	if (i > 0 && nums[i] == nums[i-1] && !visited[i-1])
	  continue;
	else
	  visited[i] = true;
	path.push_back(nums[i]);
	++step;
	DFS(nums, results, path, step, visited);
	--step;
	visited[i] = false;
	path.pop_back();
      }                
    }
  }
};
