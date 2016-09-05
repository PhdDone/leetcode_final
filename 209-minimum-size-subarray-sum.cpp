/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int start = 0; int end = 0;
    int curSum = 0;
    int N = nums.size();
    int minLen = N + 1; //init to be N + 1, not INT_MAX
    while (end < N) {
      while (curSum < s && end < N) { //also check end < N
        curSum += nums[end];
        end++; // end is actually not in the curSum
      }
      while (curSum >= s && start < end) {
        if (end - start < minLen) minLen = end - start; //don't need cur - start + 1, better to use end,
        //cuz cur is actually the next of the one already in the curSum, cur is not in the curSum yet
        curSum -= nums[start];
        start++;
      }
    }
    return minLen == N+1? 0 : minLen;
  }
};
