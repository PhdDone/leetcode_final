/*
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Given points = [[1,1],[-1,1]], return true.

Example 2:
Given points = [[1,1],[-1,-1]], return false.

Follow up:
Could you do better than O(n2)?

Hint:

Find the smallest and largest x-value for all points.
*/


class Solution {
public:
  bool isReflected(vector<pair<int, int>>& points) {
    unordered_map<int, unordered_set<int>> M;
    int mn = INT_MAX;
    int mx = INT_MIN;
    for (auto p : points) {
      if (p.first > mx) mx = p.first;
      if (p.first < mn) mn = p.first;
      M[p.first].insert(p.second);
    }

    double middle = (double)(mx - mn) / 2 + mn; // cast to double !!!!

    for (auto p : points) {
      int x_r = middle - p.first + middle; // find the reverse of x (x_r)
      if (!M.count(x_r) || !M[x_r].count(p.second)) {
        return false;
      }
    }
    return true;
  }
};
