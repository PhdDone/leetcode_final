/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
Show Company Tags
Show Tags
Show Similar Problems
*/


class Solution {
public:
  int longestPalindrome(string s) {
    sort(s.begin(), s.end());
    int res = 0;
    int N = s.size();
    if (N == 0) return 0;
    if (N == 1) return 1;
    bool hasSingle = false;

    for (int i = 0; i < N;) {
      if (s[i] == s[i+1]) {
        res +=2;
        i += 2;
      }
      else {
        hasSingle = true;
        ++i;
      }
    }
    if (hasSingle) {
      return res+1;
    }
    return res;
  }
};
