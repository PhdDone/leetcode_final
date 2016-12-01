

class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int res = 0;
    int gIdx = 0;
    int sIdx = 0;
    int N = g.size();
    int M = s.size();
    while(gIdx < N && sIdx < M) {
      if (g[gIdx] <= s[sIdx]) {
        ++res;
        ++gIdx;
        ++sIdx;
      } else {
        ++sIdx;
      }
    }
    return res;
  }
};
