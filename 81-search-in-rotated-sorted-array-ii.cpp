/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
class Solution {
public:
  bool search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (nums[mid] == target) {
        return true;
      }
      if (nums[start] > nums[mid]) {
        if (target > nums[mid] && target <= nums[end]) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      } else { //must use else
        if (nums[start] < nums[mid]) {
          if (target >= nums[start] && target < nums[mid]) {
            end = mid - 1;
          } else {
            start = mid + 1;
          }
        } else {
          ++start; //move start to left
        }
      }

    }
    return false;
  }
};
