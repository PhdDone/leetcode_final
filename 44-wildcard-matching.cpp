/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

*/

class Solution {
public:
  bool isMatch(string s, string p) {
    int R = s.size() + 1;
    int C = p.size() + 1;
    vector<vector<bool>> dp(R, vector<bool>(C, false));

    dp[0][0] = true;
    for (int i = 1; i < R; ++i) {
      dp[i][0] = false;
    }

    for (int j = 1; j < C; ++j) {
      dp[0][j] = dp[0][j-1] && p[j-1] == '*';
    }

    for (int i = 1; i < R; ++i) {
      for (int j = 1; j < C; ++j) {
        if (p[j-1] == '*') {
          dp[i][j] = dp[i-1][j] || dp[i][j-1];
        } else {
          if(p[j-1] == '?' || p[j-1] == s[i-1]) {
            dp[i][j] = dp[i-1][j-1];
          }
        }
      }
    }
    return dp[R-1][C-1];
  }
};
