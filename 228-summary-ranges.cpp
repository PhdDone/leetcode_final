/*
Given a sorted integer array without duplicates, return the summary of its ranges.

  For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/


class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    int N = nums.size();
    vector<string> result;
    if (N <= 0) return result;
        
    vector<int> tmp;
    for (int i = 0; i < N; ++i) {
      if (i == 0 || (i > 0 && nums[i-1] + 1 == nums[i])) {
	tmp.push_back(nums[i]);
      }
      else {
	stringstream range;
	if (tmp.size() > 1) {
	  range << *tmp.begin() << "->" << tmp.back(); //.back() return the value, not the iterator
	}
	else {
	  range << tmp[0];
	}
	tmp = vector<int>{};
	result.push_back(range.str());
	tmp.push_back(nums[i]);
      }
    }
    //always clean up the cached tmp
    stringstream range;
    if (tmp.size() > 1) {
      range << *tmp.begin() << "->" << tmp.back();
    }
    else {
      range << tmp[0];
    }
    result.push_back(range.str());
    return result;
  }
};
