/*
Given an array of integers, every element appears three times except for one. Find that single one.

  Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    vector<int> digits(32, 0);
    for (auto num : nums) {
      for (int i = 0; i < 32; ++i) {
	digits[i] += (num >> i) & 1;
      }
    }
    int res = 0;
    for (int i = 0; i < 32; ++i) {
      if (digits[i] % 3 != 0) {
	res += 1 << i;
      }
    }
    return res;
  }
};
