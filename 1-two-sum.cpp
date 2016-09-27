/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

  You may assume that each input would have exactly one solution.

  Example:
  Given nums = [2, 7, 11, 15], target = 9,

  Because nums[0] + nums[1] = 2 + 7 = 9,
  return [0, 1].
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
