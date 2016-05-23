/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

  For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
  the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/



class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int N = nums.size();
    int sum = 0;
    int prevSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < N; ++i) {
      if (prevSum > 0)              //if prevSum > 0, we can still accumulate it
	sum = prevSum + nums[i];
      else
	sum = nums[i];
      prevSum = sum;
      maxSum = max(maxSum, sum);
    }
    return maxSum;
  }
};
