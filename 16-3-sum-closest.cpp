/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

  For example, given array S = {-1 2 1 -4}, and target = 1.

  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int minDiff = INT_MAX;
    int res = 0;
    sort(nums.begin(), nums.end());
    int N = nums.size();
    for (int i = 0; i < N - 2; ++i) {
      int start = i + 1;
      int end = N - 1;
      while (start < end) {
	int cur = nums[i] + nums[start] + nums[end];
	if (cur == target) {
	  return target;
	}
	if (abs(target - cur) < minDiff) {
	  minDiff = abs(target - cur); //update minDiff!!!
	  res = cur;
	}
	if (cur < target) {
	  ++start;
	}
	if (cur > target) {
	  --end;
	}
      }
      while (i + 1 < N && nums[i] == nums[i+1]) ++i; //skip duplication
    }
    return res;
  }
};
