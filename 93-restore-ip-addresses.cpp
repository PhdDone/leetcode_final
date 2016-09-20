/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

  For example:
  Given "25525511135",

  return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string path;
    int start = 0;
    int step = 0;
    dfs(s, path, start, step, res);
    return res;
  }

  void dfs(const string& s, string path, int start, int step, vector<string>& res) { //no reference to path
    if (start == s.size() && step == 4) {
      path.resize(path.size() - 1);
      res.push_back(path);
      return;
    }

    if (s.size() - start < (4 - step))
      return;
    if (s.size() - start > 3*(4 - step))
      return;
    int num = 0;
    for (int i = start; i < start + 3; ++i) { // i < start + 3!!!
      num = num * 10 + (s[i] - '0');
      if (num <= 255) {
        path += s[i];
        dfs(s, path + '.', i + 1, step + 1, res); // if pass "path + '.', then can't use reference!!!"
        // no need to pop path.back();
      }
      if (num == 0) break; //prefix 0 is not allowed, single 0 is allowed
    }
  }
};
