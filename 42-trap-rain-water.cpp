/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

  For example,
  Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
class Solution {
public:
  int trap(vector<int>& height) {
    int N = height.size();
    vector<int> leftMax;
    vector<int> rightMax;
    int lmax = INT_MIN;
    int rmax = INT_MIN;
    int res = 0;
    for (int i = 1; i < N - 1; ++i) {
      if (height[i-1] > lmax) {
        lmax = height[i-1];
      }
      leftMax.push_back(lmax);
    }
    for (int i = N-2; i > 0; --i) {
      if (height[i+1] > rmax) {
        rmax = height[i+1];
      }
      //rightMax.push_back(rmax);
      rightMax.insert(rightMax.begin(), rmax); //insert to the begin!!!
    }

    for (int i = 0; i < N-2; ++i) {
      int h = min(leftMax[i], rightMax[i]);
      int tmp = h - height[i+1];
      if (tmp > 0) res += tmp;
    }
    return res;
  }
};
