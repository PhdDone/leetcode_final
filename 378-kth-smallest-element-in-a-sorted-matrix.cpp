//https://www.hrwhisper.me/leetcode-kth-smallest-element-sorted-matrix/

/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

  Note that it is the kth smallest element in the sorted order, not the kth distinct element.

  Example:

  matrix = [
            [ 1,  5,  9],
            [10, 11, 13],
            [12, 13, 15]
            ],
  k = 8,

  return 13.
  Note:
  You may assume k is always valid, 1 ≤ k ≤ n2.
  */

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int L = matrix[0][0], R = matrix[n - 1][n - 1];
    while (L < R) {
      int mid = L + ((R - L) >> 1);
      int temp = search_lower_than_mid(matrix, mid, n);
      if (temp < k) L = mid + 1;
      else R = mid;
    }
    return L;
  }

  //search from the bottom left!!!
  int search_lower_than_mid(const vector<vector<int>>& matrix, int x, const int n) {
    int i = n - 1, j = 0, cnt = 0;
    while (i >= 0 && j < n) {
      if (matrix[i][j] <= x) {
        j++;
        cnt += i + 1;
      }
      else i--;
    }
    return cnt;
  }
};
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int L = matrix[0][0], R = matrix[n - 1][n - 1];
    while (L < R) {
      int mid = L + ((R - L) >> 1);
      int temp = search_lower_than_mid(matrix, mid, n);
      if (temp < k) L = mid + 1;
      else R = mid;
    }
    return L;
  }
  int search_lower_than_mid(const vector<vector<int>>& matrix, int x, const int n) {
    int i = n - 1, j = 0, cnt = 0;
    while (i >= 0 && j < n) {
      if (matrix[i][j] <= x) {
        j++;
        cnt += i + 1;
      }
      else i--;
    }
    return cnt;
  }
};
