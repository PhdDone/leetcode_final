/*Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
  For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].*/

class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int N = nums.size();
    for (int i = 2; i < N; i = i + 2) {
      swap(nums[i-1], nums[i]);
    }
  }
};
