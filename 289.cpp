

/*
encode to :

0: dead -> dead
1: alive -> alive
2: alive -> dead
3: dead -> alive

decode:
state % 2 == 1? alive : dead
*/
public class Solution {
    public void gameOfLife(int[][] board) {
      int m = board.length, n = board[0].length;
      for(int i = 0; i < m; i++){
	for(int j = 0; j < n; j++){
	  int lives = 0;

	  if(i > 0){
	    lives += board[i - 1][j] == 1 || board[i - 1][j] == 2 ? 1 : 0;
	  }

	  if(j > 0){
	    lives += board[i][j - 1] == 1 || board[i][j - 1] == 2 ? 1 : 0;
	  }

	  if(i < m - 1){
	    lives += board[i + 1][j] == 1 || board[i + 1][j] == 2 ? 1 : 0;
	  }

	  if(j < n - 1){
	    lives += board[i][j + 1] == 1 || board[i][j + 1] == 2 ? 1 : 0;
	  }

	  if(i > 0 && j > 0){
	    lives += board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 2 ? 1 : 0;
	  }

	  if(i < m - 1 && j < n - 1){
	    lives += board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == 2 ? 1 : 0;
	  }

	  if(i > 0 && j < n - 1){
	    lives += board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 2 ? 1 : 0;
	  }

	  if(i < m - 1 && j > 0){
	    lives += board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 2 ? 1 : 0;
	  }

	  if(board[i][j] == 0 && lives == 3){
	    board[i][j] = 3;
	  } else if(board[i][j] == 1){
	    if(lives < 2 || lives > 3) board[i][j] = 2;
	  }
	}
      }

	for(int j = 0; j < n; j++){
	  board[i][j] = board[i][j] % 2;
	}
      }
    }
}

//ref: https://segmentfault.com/a/1190000003819277
