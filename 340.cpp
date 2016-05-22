/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

  For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.

Show Company Tags
Show Tags
Show Similar Problems
*/

//longest substring with at most two distinct characters
class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    if (s.size() == 0 || k == 0) return 0;
    int n = s.size();
    int pstart = 0, pend = 0, max_len = 0, num_chars = 0;
    int hash_table[256] = {0};
    
    for (; pend < n; ++pend) {
      hash_table[s[pend]]++;
      if (hash_table[s[pend]] == 1) {//new char comes in
	++num_chars;
	while (pstart < n && hash_table[s[pstart]] != 0 && num_chars > k) {
	  hash_table[s[pstart]]--;
	  if (hash_table[s[pstart]] == 0) num_chars--;
	  pstart++;
	}
      }
      max_len = max(max_len, pend - pstart + 1);
    }
    return max_len;
  }
};
