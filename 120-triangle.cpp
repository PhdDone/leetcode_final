/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

  For example, given the following triangle
  [
   [2],
   [3,4],
   [6,5,7],
   [4,1,8,3]
   ]
  The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.size() == 0) return 0;
    if (triangle.size() == 1) return triangle[0][0];

    int curLine = 0;
    int Row = triangle.size();
    while (curLine < Row) {
      int prevLine = curLine - 1;
      if (prevLine >= 0) {
        int Col = triangle[curLine].size();
        for (int i = 0; i < Col; ++i) {
          int a = (i-1 >= 0)? triangle[prevLine][i-1] : INT_MAX;
          int b = (i < triangle[prevLine].size())? triangle[prevLine][i] : INT_MAX;
          triangle[curLine][i] += min(a, b);
        }
      }
      ++curLine;
    }
    return *std::min_element(triangle[curLine - 1].begin(), triangle[curLine - 1].end());
  }
};
