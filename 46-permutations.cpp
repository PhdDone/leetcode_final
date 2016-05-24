/*
Given a collection of distinct numbers, return all possible permutations.

  For example,
  [1,2,3] have the following permutations:
  [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

Show Company Tags
Show Tags
Show Similar Problems
*/


class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    int N = nums.size();
    vector<vector<int>> results;
    vector<bool> visited(N, false); //use visited array to indicate it has been used or not
    if (N==0) return results;
    vector<int> path;
    int step = 0;
    DFS(nums, path, step, results, visited);
    return results;
  }
    
  void DFS(vector<int> const& nums, vector<int>& path, int step, vector<vector<int>> &results, vector<bool> &visited) {
    if (step == nums.size()) {
      results.push_back(path);
      return;
    }
        
    for (int i = 0; i < nums.size(); ++i) {
      if (!visited[i]) {
	path.push_back(nums[i]);
	visited[i] = true;
	DFS(nums, path, step + 1, results, visited);
	visited[i] = false;
	path.pop_back();
      }
    }
  }
};
