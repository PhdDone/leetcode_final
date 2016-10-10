/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

  Example:
  Given nums = [-2, 0, 3, -5, 2, -1]

  sumRange(0, 2) -> 1
  sumRange(2, 5) -> -1
  sumRange(0, 5) -> -3
*/


class NumArray {
public:
  vector<int> dp;
  NumArray(vector<int> &nums) {
    int N = nums.size();
    dp.resize(N+1); //resize to N+1
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
      dp[i+1] = dp[i] + nums[i];
    }
  }

  int sumRange(int i, int j) {
    return dp[j+1] - dp[i];
  }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
