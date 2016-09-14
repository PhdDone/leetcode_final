//http://yucoding.blogspot.com/2015/10/leetcode-question-maximal-square.html

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int row = matrix.size();
    if (row == 0) return 0;
    int col = matrix[0].size();
    int res = 0;
    vector<vector<int>> dp(row, vector<int>(col, 0));

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (matrix[i][j] == '1') {
          dp[i][j] = 1;
        }
      }
    }

    for (int i = 1; i < row; ++i) {
      for (int j = 1; j < col; ++j) {
        if (dp[i][j] == 1) {
          dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
        }
        if (dp[i][j] > res) res = dp[i][j];
      }
    }
    return res * res; // !!! return square !!!
  }
};
