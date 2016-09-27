/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

  For example,
  Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

  Window position                Max
  ---------------               -----
  [1  3  -1] -3  5  3  6  7       3
   1 [3  -1  -3] 5  3  6  7       3
   1  3 [-1  -3  5] 3  6  7       5
   1  3  -1 [-3  5  3] 6  7       5
   1  3  -1  -3 [5  3  6] 7       6
   1  3  -1  -3  5 [3  6  7]      7
  Therefore, return the max sliding window as [3,3,5,5,6,7].

  Note:
  You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/
//https://segmentfault.com/a/1190000003903509

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    int N = nums.size();
    if (N < k) return res;
    list<int> indexQueue;
    for (int i = 0; i < N; ++i) {
      while (!indexQueue.empty() && i - indexQueue.front() >= k) {
        indexQueue.pop_front();
      }
      while (!indexQueue.empty() && nums[indexQueue.back()] < nums[i]) {
        indexQueue.pop_back();
      }
      indexQueue.push_back(i);
      if (i + 1 >= k) res.push_back(nums[indexQueue.front()]);
    }
    return res;
  }
};