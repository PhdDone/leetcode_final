/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

  Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

  Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

  Note:
                             The order of returned grid coordinates does not matter.
  Both m and n are less than 150.
  Example:

                             Given the following 5x5 matrix:

                               Pacific ~   ~   ~   ~   ~
  ~  1   2   2   3  (5) *
  ~  3   2   3  (4) (4) *
  ~  2   4  (5)  3   1  *
  ~ (6) (7)  1   4   5  *
  ~ (5)  1   1   2   4  *
            *   *   *   *   * Atlantic

  Return:

                             [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

*/

class Solution {
public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<pair<int, int>> res;
    int R = matrix.size();
    if (R == 0) return res;
    int C = matrix[0].size();

    vector<vector<bool>> pacific(R, vector<bool>(C, false));
    vector<vector<bool>> atlantic(R, vector<bool>(C, false));

    for (int i = 0; i < C; ++i) {
      DFS(matrix, pacific, INT_MIN, 0, i);
      DFS(matrix, atlantic, INT_MIN, R - 1, i);
    }

    for (int j = 0; j < R; ++j) {
      DFS(matrix, pacific, INT_MIN, j, 0);
      DFS(matrix, atlantic, INT_MIN, j, C - 1);
    }

    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (pacific[i][j] && atlantic[i][j]) { //WRONG! pacific[i][j] == atlantic[i][j] == true
          res.push_back(make_pair(i, j));
        }
      }
    }
    return res;
  }

  void DFS(const vector<vector<int>>& matrix, vector<vector<bool>>& visited, int pre, int x, int y) {
    if ( x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size() || visited[x][y] || matrix[x][y] < pre) return;

    visited[x][y] = true;
    DFS(matrix, visited, matrix[x][y], x + 1, y);
    DFS(matrix, visited, matrix[x][y], x - 1, y);
    DFS(matrix, visited, matrix[x][y], x, y + 1);
    DFS(matrix, visited, matrix[x][y], x, y - 1);
  }
};
