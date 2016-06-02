class Solution {
  //live -> die = 1
  //die -> die = 2
  //live -> live = 3
  //die -> live = 4
public:
  void gameOfLife(vector<vector<int>>& board) {
    int R = board.size();
    if (R == 0) return;
    int C = board[0].size();
        
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
	int count = CountN(board, i, j);
	if (count < 2) {
	  if (board[i][j])
	    board[i][j] = 1;
	  else
	    board[i][j] = 2;
	}
	else if (count == 2) {
	  if (board[i][j])
	    board[i][j] = 3;
	  else
	    board[i][j] = 2;
	}
	else if (count == 3) {
	  if (board[i][j])
	    board[i][j] = 3;
	  else
	    board[i][j] = 4;
	}
	else {
	  if (board[i][j])
	    board[i][j] = 1;
	  else
	    board[i][j] = 2;
	}
      }
    }
        
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
	board[i][j] = board[i][j] <= 2? 0 : 1;
      }
    }
  }
    
  int CountN(vector<vector<int>>& board, int i, int j) {
    int count = 0;
    if (i - 1 >= 0 && j - 1 >= 0)
      count += board[i-1][j-1] % 2;
    if (i + 1 < board.size() && j + 1 < board[0].size())
      count += board[i+1][j+1] % 2;
    if (i - 1 >= 0)
      count += board[i-1][j] % 2;
    if (j - 1 >= 0)
      count += board[i][j-1] % 2;
    if (i + 1 < board.size())
      count += board[i+1][j] % 2;
    if (j + 1 < board[0].size())
      count += board[i][j+1] % 2;
    if (i + 1 < board.size() && j - 1 >= 0)
      count += board[i+1][j-1] % 2;
    if (i - 1 >= 0 && j + 1 < board[0].size())
      count += board[i-1][j+1] % 2;
        
    return count;
  }
};
