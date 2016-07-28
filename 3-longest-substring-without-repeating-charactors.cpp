/*Given a string, find the length of the longest substring without repeating characters.

  Examples:

  Given "abcabcbb", the answer is "abc", which the length is 3.

    Given "bbbbb", the answer is "b", with the length of 1.

    Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    const int ASCII_MAX = 255;
    int last[ASCII_MAX]; // int last[ASCII_MAX] = {-1} only set the first element to be one
    std::fill(last, last+ASCII_MAX, -1);
    int start = 0;
    int max_len = 0;

    int N = s.size();
    for (int i = 0; i < N; ++i) {
      if (last[s[i]] >= start){
        max_len = max(i - start, max_len);
        start = last[s[i]] + 1;
        cout << i;
      }
      last[s[i]] = i;
    }
    //abcdef
    return max(N - start, max_len);
  }
};
