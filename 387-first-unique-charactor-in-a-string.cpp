class Solution {
public:
  int firstUniqChar(string s) {
    unordered_map<char, int> counts;
    int N = s.size();
    for (int i = 0; i < N; ++i) {
      auto iter = counts.find(s[i]);
      if (iter == counts.end()) {
        counts[s[i]] = 1;
      } else {
        ++counts[s[i]];
      }
    }

    for (int i = 0; i < N; ++i) {
      if (counts[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};
