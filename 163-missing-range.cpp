/*
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

  For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

class Solution {
public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    nums.insert(nums.begin(), lower-1);
    nums.insert(nums.end(), upper+1);
    int N = nums.size();
    vector<string> res;
    for (int i = 0; i < N - 1; ++i) {
      int left = nums[i];
      int right = nums[i+1];
      if (left != right - 1) {
	if (right - left == 2) {
	  res.push_back(to_string(left + 1));
	}
	else {
	  stringstream tmp;
	  tmp << left + 1 << "->" << right - 1;
	  res.push_back(tmp.str());
	}
      }
    }
    return res;
  }
};
