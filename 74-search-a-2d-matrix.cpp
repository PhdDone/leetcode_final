

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int R = matrix.size();
    if (R == 0) return false;
    int C = matrix[0].size();

    int start  = 0, end = R - 1;

    while (start <= end) {
      //int mid = (start + end) / 2;
      int mid = start + ((end - start ) >> 1); //warning: operator '>>' has lower precedence than '+'; '+' will be evaluated first
      if (target == matrix[mid][0]) return true;
      if (target > matrix[mid][0]) {
        start += 1;
      } else {
        end -= 1;
      }
    }

    int targetRow = end;
    //cout << targetRow << endl;
    if (targetRow < 0) return false; //check target row out of range!!
    start = 0;
    end = C - 1;

    while (start <= end) {
      int mid = start + ((end - start) >> 1);
      //cout << start << " " << end << endl;
      //int x = (1 - 1) >> 1 + 1;
      //cout << x << "DDD" << endl;
      if (target == matrix[targetRow][mid]) return true;
      if (target > matrix[targetRow][mid]) {
        start += 1;
      } else {
        end -= 1;
      }
    }
    return false;
  }
};
