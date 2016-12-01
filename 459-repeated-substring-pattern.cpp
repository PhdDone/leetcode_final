/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/
class Solution {
public:
  bool repeatedSubstringPattern(string str) {
    int N = str.size();
    bool res = false;
    for (int len = 1; len <= N / 2; ++len) {
      if ( N % len != 0) continue;
      res = true;
      for  (int i = 0; i < len; ++i) {
        int c = i + len;
        while (c < N) {
          if (str[i] != str[c]) {
            res = false;
            break;
          } else {
            c += len;
          }
        }
      }
      if (res == true)
        return true;
    }
    return res;
  }
};
