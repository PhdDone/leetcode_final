/*
Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
  A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
*/

//http://www.cnblogs.com/grandyang/p/5467118.html

class TicTacToe {
public:
  /** Initialize your data structure here. */
  TicTacToe(int n) {
    N = n;
    rows = vector<int>(N, 0);
    cols = vector<int>(N, 0);
    diag = 0;
    rev_diag = 0;
  }
    
  /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
  int move(int row, int col, int player) {
    int add = player == 1? -1: 1;   //one player always +1 to that row, the other always -1
    rows[row] += add;
    cols[col] += add;
    if (row == col) diag += add;
    if (row == N - col - 1) rev_diag += add;
    if (abs(rows[row]) == N || abs(cols[col]) == N || abs(diag) == N || abs(rev_diag) == N) {
      return player; //return player, don't assume who's first
    }
    return 0;
  }
private:
  vector<int> rows, cols; //use rows to record row, if the absolute value  reaches N then someone wins
  int diag, rev_diag, N;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
