/*Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
*/
  


class Solution {
public:
  int maxArea(vector<int>& height) {
    int start = 0;
    int end = height.size() - 1;
    int res = INT_MIN;
    while (start < end) {
      int h = min(height[start], height[end]);
      res = max(res, h * (end - start));

      if (height[start] <= height[end]) {
        ++start;
      } else {
        --end;
      }
    }
    return res;
  }
};
