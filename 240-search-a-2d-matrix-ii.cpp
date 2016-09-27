 /* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

  Consider the following matrix:
*/

//search from top right
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int Row = matrix.size();
    if (Row == 0) return false;
    int Col = matrix[0].size();
    int i = 0, j = Col - 1;
    while (i < Row && j >= 0) {
      int value = matrix[i][j];
      if (value == target)
        return true;
      else {
        if (value > target) {
          --j;
        } else {
          ++i;
        }
      }
    }
    return false;
  }
};
