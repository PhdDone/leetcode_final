/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
  [1,3,5,6], 5 → 2
  [1,3,5,6], 2 → 1
  [1,3,5,6], 7 → 4
  [1,3,5,6], 0 → 0
*/
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int N = nums.size();
    for (int i = 0; i < N; ++i) {
      if (nums[i] >= target ) return i; 
    }
    return N;
  }
};

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int N = nums.size();
    int start = 0, end = N - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] == target) {
        return mid;
      } else {
        if (target > nums[mid]) {
          start  = mid + 1;
        } else {
          end = mid - 1;
        }
      }
    }
    return start;
  }
};
