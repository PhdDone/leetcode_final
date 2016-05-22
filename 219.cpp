/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/
class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> numIndex;
    int N = nums.size();
    for (int i = 0; i < N; ++i) {
      auto iter = numIndex.find(nums[i]);
      if (iter == numIndex.end()) {
	numIndex[nums[i]] = i;
      }
      else {
	if (i - iter->second <= k) {
	  return true;
	}
	else {
	  numIndex[nums[i]] = i; //remeber to update!!!
	}
      }
    }
    return false;
  }
};
