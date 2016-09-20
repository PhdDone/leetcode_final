//http://bookshadow.com/weblog/2016/09/04/leetcode-longest-substring-with-at-least-k-repeating-characters/
//http://www.cnblogs.com/grandyang/p/5852352.html
/*
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
Show Company Tags
*/

class Solution {
public:
  int longestSubstring(string s, int k) {
    bool valid[26] = {false};
    int count[26] = {0};
    int N = s.size();
    if (N < k) return 0;

    for (int i = 0; i < N; ++i) {
      ++count[s[i] - 'a'];
      if (count[s[i] - 'a'] == k) {
        valid[s[i] - 'a'] = true;
      }
    }
    //check full valid!!!
    bool fullValid = true;
    for (int i = 0; i < 26; ++i) {
      if (count[i] > 0 && valid[i] == false) {
        fullValid = false;
      }
    }

    if (fullValid) {
      return N;
    }

    int maxLen = 0;
    int lastBegin = 0;
    for (int i = 0; i < N; ++i) { //find the first invalid one, recursively get the length of the sub string
      if (valid[s[i] - 'a'] == false) {
        maxLen = max(maxLen, longestSubstring(s.substr(lastBegin, i - lastBegin), k));
        lastBegin = i + 1;
      }
    }
    //calculate the tail!!
    maxLen = max(maxLen, longestSubstring(s.substr(lastBegin, N - lastBegin), k));
    return maxLen;
  }
};
