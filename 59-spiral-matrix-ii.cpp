/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

  For example,
  Given n = 3,

  You should return the following matrix:
  [
   [ 1, 2, 3 ],
   [ 8, 9, 4 ],
   [ 7, 6, 5 ]
   ]
*/


class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    if (n ==0) return res;
    int BeginX = 0;
    int EndX = n-1;
    int BeginY = 0;
    int EndY = n-1;

    int num = 1;
    while (true) {
      for (int j = BeginY; j <= EndY; ++j) res[BeginX][j] = num++;
      if (++BeginX > EndX) break;
      for (int i = BeginX; i <= EndX; ++i) res[i][EndY] = num++;
      if (BeginY > --EndY) break;
      for (int j = EndY; j >= BeginY; --j) res[EndX][j] = num++;
      if (--EndX < BeginX) break;
      for (int i = EndX; i >= BeginX; --i) res[i][BeginY] = num++;
      if (++BeginY > EndY) break;
    }
    return res;
  }
};
