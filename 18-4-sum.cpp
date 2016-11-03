//http://bangbingsyb.blogspot.com/2014/11/leetcode-4sum.html

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int N = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i1 = 0; i1 < N - 3; ++i1) {
      while (i1 > 0 && nums[i1] == nums[i1 - 1]) ++i1; // !!! how to skip dup, first use it, then check if it's the same with prev used one
      for (int i2 = i1 + 1; i2 < N - 2; ++i2) {
        while (i2 != i1 + 1 && nums[i2] == nums[i2 - 1]) ++i2; // same here, first time i2 == i1 + 1, don't skip
        int i3 = i2 + 1, i4 = N - 1;
        while (i3 < i4) {
          int val = nums[i1] + nums[i2] + nums[i3] + nums[i4];
          if ( val == target) {
            res.push_back(vector<int>{nums[i1], nums[i2], nums[i3], nums[i4]});
            ++i3;
            --i4;
            while (nums[i3] == nums[i3 - 1]) ++i3;
            while (nums[i4] == nums[i4 + 1]) --i4;
          } else {
            if (val < target) {
              ++i3;
              while (nums[i3] == nums[i3 - 1]) ++i3;
            } else {
              --i4;
              while (nums[i4] == nums[i4 + 1]) --i4;
            }
          }
        }
      }
    }
    return res;
  }
};
