/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

  Find the maximum coins you can collect by bursting the balloons wisely.

  Note:
  (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
  (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

  Example:

  Given [3, 1, 5, 8]

  Return 167

  nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
     coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
  Credits:
  Special thanks to @dietpepsi for adding this problem and creating all test cases.

*/




//其中dp[i][j]表示打爆区间[i,j]中的所有气球能得到的最多金币。

//dp[i][j] = max(dp[i][j], nums[i - 1]*nums[k]*nums[j + 1] + dp[i][k - 1] + dp[k + 1][j])


for (int len = 1; len <= n; ++len) { // use the length to iterate over the dp
  //len(dp[0][0]) == 1
  // nums = [1, {1, 2, 3,} 1] //insert 1 to the begin() and end()
  // dp[1][1] dp[2][2], dp[3][3]
  //dp[1][2], dp[2][3],
  //dp[1][3] = max(dp[1][3], nums[0] * nums[1] * nums[4] + dp[1][0] + dp[2][3]） //k = i, k <= j
  //dp[1][3] = max(dp[1][3], nums[0] * nums[2] * nums[4] + dp[1][1] + dp[3][3])
  //len(dp[0][1]) == 2
  //len(dp[0][2]) == 3
  for (int left = 1; left <= n - len + 1; ++left) {
    int right = left + len - 1;
    for (int k = left; k <= right; ++k) {
      dp[left][right] = max(dp[left][right], nums[left - 1] * nums[k] * nums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
    }
  }
 }
return dp[1][n];



// Recursion
class Solution {
public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int> > dp(nums.size(), vector<int>(nums.size() , 0));
    return burst(nums, dp, 1 , n);
  }
  int burst(vector<int> &nums, vector<vector<int> > &dp, int left, int right) {
    if (left > right) return 0;
    if (dp[left][right] > 0) return dp[left][right];
    int res = 0;
    for (int k = left; k <= right; ++k) {
      res = max(res, nums[left - 1] * nums[k] * nums[right + 1] + burst(nums, dp, left, k - 1) + burst(nums, dp, k + 1, right));
    }
    dp[left][right] = res;
    return res;
  }
};
