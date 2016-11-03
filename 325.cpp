/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
*/

//http://blog.csdn.net/bearkino/article/details/50480213

//timeoout
#include <numeric>
class Solution {
public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    int result = 0;
    for (auto i = nums.begin(); i != nums.end(); ++i) {
      for (auto j = i; j != nums.end(); ++j) {
	auto curSum = std::accumulate(i, j, 0);
	if (curSum == k) result = std::max(result, int(j - i));
      }
    }
    return result;
  }
};

//O(n)

#include <numeric>
class Solution {
public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    m.insert(pair<int, int>(0, -1)); //if accumulated sum == k, the current index i - (-1) == i + i is the len!!
        
    int acc = 0;
    int result = 0;
    for(int i = 0, j = nums.size(); i < j; ++i) {
      acc += nums[i];
      if (m.count(acc) == 0) { //only insert if we don't have it!!!
	m.insert(pair<int, int>(acc, i));
      }
      auto iter = m.find(acc - k); // acc - k !!!!
      if (iter != m.end()) {
	result = max(result, i - iter->second);
      }
    }
    return result;
  }
};

//record accumulated sum, try to find (key = sum - k)

//https://segmentfault.com/a/1190000005771068
