//https://segmentfault.com/a/1190000004675223#articleHeader5
/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    int N = nums.size();
    if (N == 0) return;

    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());

    int k = (N + 1) >> 1; // N + 1
    int j = N;

    for (int i = 0; i < N; ++i) {
      nums[i] = i & 1? tmp[--j] : tmp[--k];
    }
  }
};
