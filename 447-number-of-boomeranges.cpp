/*

Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/

class Solution {
public:
  double getSqrDistance(pair<int, int> x, pair<int, int> y) { // return the square error, don't calculate the sqrt
    return pow(x.first - y.first, 2) + pow(x.second - y.second, 2);
  }

  int numberOfBoomerangs(vector<pair<int, int>>& points) {
    int N = points.size();
    int res = 0;
    for (int i = 0; i < N; ++i) {
      unordered_map<double, int> disToFreq;
      for (int j = 0; j < N; ++j) {
        if (j == i) continue;
        int dis = getSqrDistance(points[i], points[j]);
        ++disToFreq[dis];
      }
      for (auto d : disToFreq) {
        res += d.second * (d.second - 1);
      }
    }
    return res;
  }
};
