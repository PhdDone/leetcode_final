/*
After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

  Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

// DP
class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
    return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size())); //max of don't rob the first or don't robe the last 
  }
  int rob(vector<int> &nums, int left, int right) {
    if (right - left <= 1) return nums[left];
    vector<int> dp(right, 0);
    dp[left] = nums[left];
    dp[left + 1] = max(nums[left], nums[left + 1]);
    for (int i = left + 2; i < right; ++i) {
      dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }
    return dp.back();
  }
};

//http://www.cnblogs.com/grandyang/p/4518674.html


class Solution {
public:
  int rob(vector<int>& nums) {
    int N = nums.size();
    if (N == 0) return 0;
    if (N == 1) return nums[0];
    int left = 0; int right = N-1;
    return max(rob(nums, left, right - 1), rob(nums, left + 1, right));
  }

  int rob(vector<int>& nums, int left, int right) {
    if (left == right) return nums[left];
    if (right - left == 1) return max(nums[left], nums[right]);
    vector<int> dp(right + 1, 0); //allocate right + 1 space, because we will reach dp[right], which shoule have right + 1!!!
    dp[left] = nums[left];
    dp[left + 1] = max(nums[left + 1], nums[left]); //get the max, not just nums[left+1]

    for (int i = left+2; i <= right; ++i) {
      dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    cout << dp.back() << endl;
    return dp.back();
  }
};
