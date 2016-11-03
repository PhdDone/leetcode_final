/*
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
Given m satisfies the following constraint: 1 ≤ m ≤ length(nums) ≤ 14,000.

Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
*/

//http://www.cnblogs.com/grandyang/p/5933787.html
//binary search



class Solution {
public:
  int splitArray(vector<int>& nums, int m) {
    long long left = 0, right = 0;
    for (int num : nums) {
      left = left > num? left : num; // can't use max(int, int)
      right += num;
    }

    // left is the lower bound that every individul element is a group, nums.size() group
    // right is the total sum with one group

    //search the value that can be the upper bound of each sub group 
    while (left < right) {
      long long mid = left + ((right - left) >> 1); // need the parents!!!
      if (canSplit(nums, m, mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }

  bool canSplit(const vector<int>& nums, int m, int mid) {
    int cnt = 1;  //cnt = 1????, can think try to fill the first group
    int curSum = 0;
    for (int num : nums) {
      curSum += num;
      if (curSum > mid) {
        curSum = num; // reset curSum to the the new num
        ++cnt;
        if (cnt > m) return false;
      }
    }
    return true;
  }
};
