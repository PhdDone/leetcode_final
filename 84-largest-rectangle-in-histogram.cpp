class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    stack<int> index;

    heights.push_back(0);
    int res = 0;
    for (int i = 0; i < heights.size();) {
      if (index.empty() || heights[i] > heights[index.top()]) {
        index.push(i);
        ++i;
      } else {
        int tmp = index.top();
        index.pop();
        res = max(res, heights[tmp] * (index.empty()? i : i-index.top()-1));
      }
    }
    return res;
  }
};
