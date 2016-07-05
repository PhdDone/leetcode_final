class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> path;
    int start = 1;
    int end = 9;
    int cur = 0;
    DFS(start, end, cur, k, n, path, res);
    return res;
  }

  void DFS(int start, int end, int cur, int k, int n, vector<int>& path, vector<vector<int>>& res) {
    if (cur == k) {
      int sum = 0;
      for (int i : path) {
        sum += i;
      }
      if (sum == n)
        res.push_back(path);
      return;
    }
    for (int i = start; i <= end; ++i) {
      path.push_back(i);
      DFS(i+1, end, cur+1, k, n, path, res);
      path.pop_back();
    }
  }
};
