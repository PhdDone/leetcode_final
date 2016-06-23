//Write a function to find the longest common prefix string amongst an array of strings.

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    int N = strs.size();
    string res = "";
    if (N == 0) return res;
    int M = strs[0].size();
    for (int i = 0; i < M; ++i) {
      char cur = strs[0][i];
      for (int j = 1; j < N; ++j) {
	if (i >= strs[j].size() || strs[j][i] != cur) return res;
      }
      res += cur;
    }
    return res;
  }
};
