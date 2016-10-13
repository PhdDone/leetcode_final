//https://www.hrwhisper.me/leetcode-longest-increasing-path-matrix/

/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

//http://www.cnblogs.com/grandyang/p/5148030.html

//don't need a set to record visited, because it won't fit the matrix[nx][ny] > matrix[x][y] condition

class Solution {
public:
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  int dfs(const vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y, int R, int C) {
    if (dp[x][y]) return dp[x][y];
    int mx = 1;
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < R && ny < C && nx >= 0 && ny >= 0 && matrix[nx][ny] > matrix[x][y]) {
        int rest = dfs(matrix, dp, nx, ny, R, C);
        mx = max(mx, rest + 1);
      }
    }
    dp[x][y] = mx;
    return dp[x][y];
  }
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int R = matrix.size();
    if (R == 0) return 0;
    int C = matrix[0].size();
    vector<vector<int>> dp(R, vector<int>(C, 0));

    int res = 0;

    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        res = max(res, dfs(matrix, dp, i, j, R, C));
      }
    }

    return res;
  }


};
