/*Given a 2D board and a word, find if the word exists in the grid.

  The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

  For example,
  Given board =

  [
   ['A','B','C','E'],
   ['S','F','C','S'],
   ['A','D','E','E']
   ]
  word = "ABCCED", -> returns true,
  word = "SEE", -> returns true,
  word = "ABCB", -> returns false.
*/

class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    int Row = board.size();
    if (Row == 0) return 0;
    int Col = board[0].size();
    vector<vector<bool>> visited(Row, vector<bool>(Col, false));
    for (int i = 0; i < Row; ++i) {
      for (int j = 0; j < Col; ++j) {
        if (dfs(board, Row, Col, i, j, word, 0, visited)) return true;
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>>& board, int R, int C, int i, int j, const string& word, int index, vector<vector<bool>>& visited) {
    if (index == word.size()) return true;
    if (i < 0 || j < 0 || i >= R || j >= C || visited[i][j] || board[i][j] != word[index]) return false;
    if (visited[i][j]) return false;
    visited[i][j] = true;
    bool res = dfs(board, R, C, i + 1, j, word, index + 1, visited) ||
      dfs(board, R, C, i - 1, j, word, index + 1, visited) ||
      dfs(board, R, C, i, j + 1, word, index + 1, visited) ||
      dfs(board, R, C, i, j - 1, word, index + 1, visited);
    if (res == true) return true;
    else visited[i][j] = false;
    return false;
  }
};
