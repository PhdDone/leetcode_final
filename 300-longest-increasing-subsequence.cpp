/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

  For example,
  Given [10, 9, 2, 5, 3, 7, 101, 18],
  The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

  Your algorithm should run in O(n2) complexity.

  Follow up: Could you improve it to O(n log n) time complexity?
*/
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int N = nums.size();
    vector<int> f(N, 1);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (nums[i] > nums[j]) {
          f[i] = max(f[i], 1 + f[j]);
        }
      }
    }

    int res = 0;
    for (int i : f) {
      res = max(res, i);
    }
    return res;
  }
};
