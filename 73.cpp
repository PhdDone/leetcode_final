
/**
 * 73. Set Matrix Zeroes 
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 */
class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int row = matrix.size();
    if (row == 0) return;
    int col = matrix[0].size();
    if (col == 0) return;
        
    bool firstRow = false;
    bool firstCol = false;
        
    for (int i = 0; i < row; ++i) {
      if (matrix[i][0] == 0) {
	firstCol = true;
      }
    }
        
    for (int j = 0; j < col; ++j) {
      if (matrix[0][j] == 0) {
	firstRow = true;
	break;
      }
    }
        
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
	if (matrix[i][j] == 0) {
	  matrix[0][j] = 0;
	  matrix[i][0] = 0;
	}
      }
    }
        
    for (int j = 1; j < col; ++j) {  //j starts from 1
      if (matrix[0][j] == 0) {
	for (int i = 0; i < row; ++i) {
	  matrix[i][j] = 0;
	}
      }
    }
        
    for (int i = 1; i < row; ++i) { //i starts from 1
      if (matrix[i][0] == 0) {
	for (int j = 0; j < col; ++j) {
	  matrix[i][j] = 0;
	}
      }
    }
        
    if (firstRow) {
      for (int j = 0; j < col; ++j) {
	matrix[0][j] = 0;
      }
    }
        
    if (firstCol) {
      for (int i = 0; i < row; ++i) {
	matrix[i][0] = 0;
      }
    }
  }
};
