/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

  For example,
  If n = 4 and k = 2, a solution is:

[
 [2,4],
 [3,4],
 [2,3],
 [1,2],
 [1,3],
 [1,4],
]
*/
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> path;
    int start = 1;
    dfs(n, k, res, path, start);
    return res;
  }
    
  void dfs(int n, int k, vector<vector<int>>& res, vector<int>& path, int start) {
    if (path.size() == k) {
      res.push_back(path);
      return;
    }
    for (int i = start; i <= n; ++i) {
      path.push_back(i);
      dfs(n, k, res, path, i + 1);
      path.pop_back();
    }
  }
    
};
