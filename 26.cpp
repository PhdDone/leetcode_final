/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

  Do not allocate extra space for another array, you must do this in place with constant memory.

							       For example,
							       Given input array nums = [1,1,2],

							       Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

//https://siddontang.gitbooks.io/leetcode-solution/content/array/remove_duplicates_from_sorted_array.html

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int i = 0;
    for (int j = 1; j < n; ++j) {
      if (nums[i] != nums[j]) {
	nums[++i] = nums[j];
      }
    }
    return i+1;
  }
};
