/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/
class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int N = nums.size();
    k = k % N;
    k = N - k;
    auto iter = nums.begin();
    for (int step = 0; step < k; ++step) { // < k
      iter++;
    }
    reverse(nums.begin(), iter);
    reverse(iter, nums.end());
    reverse(nums.begin(), nums.end());
  }
};
