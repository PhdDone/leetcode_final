/*
Given a list of non negative integers, arrange them such that they form the largest number.

  For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

  Note: The result may be very large, so you need to return a string instead of an integer.
*/

/*
class Solution {
public:
  string largestNumber(vector<int>& nums) {
    string res;
    string path;
    dfs(nums, res, path, 0);
    return res;
  }

  void dfs(vector<int> & nums, string& res, string& path, int start) {
    if (start == nums.size()) {
      if (path > res) {
        res = path;
        return;
      }
    }
    for (int i = start; i < nums.size(); ++i) {
      swap(nums[i], nums[start]);
      string tmp = path;
      path += to_string(nums[start]);
      dfs(nums, res, path, start + 1);
      path = tmp;
      swap(nums[i], nums[start]);
    }
  }
};
*/

class Solution {
public:
  string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int a, int b) {
        string A = to_string(a);
        string B = to_string(b);
        if (A + B > B + A) return true;
        return false;
      });
    string res;
    for (int num : nums) {
      res += to_string(num);
    }
    if (res[0] == '0') res = "0";
    return res;
  }
};
