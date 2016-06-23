/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

  For example,
  Given nums = [0, 1, 3] return 2.

  Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/
//http://www.cnblogs.com/grandyang/p/4756677.html

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int res = 0;
    int N = nums.size();
    for (int i = 0; i < N; ++i) {
      res ^= (i + 1) ^ nums[i];
    }
    return res;
  }
};
