/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

  You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Show Company Tags
Show Tags
Show Similar Problems
*/

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mapping;
    int N = nums.size();
    for (int i = 0; i < N; ++i) {
      mapping[nums[i]] = i;
    }
    vector<int> res;
    for (int i = 0; i < N; ++i) {
      int gap = target - nums[i];
      auto iter = mapping.find(gap);
      if (iter != mapping.end() && iter->second != i) { //not including the same number twice
	res.push_back(i);
	res.push_back(iter->second);
	break;
      }
    }
    return res;
  }
};
