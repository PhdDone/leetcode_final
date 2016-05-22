/*
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.  For example, given nums = [-2, 0, 1, 3], and target = 2.

*/

class Solution {
public:
  int threeSumSmaller(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n - 2; ++i) {
      int j = i + 1;
      int k = n - 1;
      while (k > j) {
	if (nums[i] + nums[j] + nums[k] < target) {
	  res += (k - j);
	  j++;                    //don't need another loop, in one loop we can move both k and j!!
	}
	else {
	  --k;
	}
      }
    }
    return res;
  }
};
