/*
Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

  You receive a valid board, made of only battleships or empty slots.
  Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
  At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
  Example:
  X..X
  ...X
  ...X
  In the above board there are 2 battleships.
  Invalid Example:
  ...X
    XXXX
    ...X
  This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
  Follow up:
  Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
*/
class Solution {
public:
  int countBattleships(vector<vector<char>>& board) {

    int res = 0;
    int R = board.size();
    if (R == 0) return 0;
    int C = board[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    for (int i = 0; i< R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (board[i][j] == 'X' && !visited[i][j]) {
          ++res;
          DFS(board, visited, i, j, R, C);
          //visited.insert(make_pair(i, j));

        }
      }
    }
    return res;
  }

  void DFS(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, int R, int C) {
    if (i < 0 || j < 0 || i >= R || j >= C) return;
    if (board[i][j] == '.' || visited[i][j]) return;
    visited[i][j] = true ;
    DFS(board, visited, i+1, j, R, C);
    DFS(board, visited, i-1, j, R, C);
    DFS(board, visited, i, j+1, R, C);
    DFS(board, visited, i, j-1, R, C);
  }
};
