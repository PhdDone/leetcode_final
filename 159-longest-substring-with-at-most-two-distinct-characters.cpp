/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

  For example, Given s = “eceba”,

  T is "ece" which its length is 3.
*/


class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int k = 2;
    int left = 0;
    int res = 0;
    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); ++i) {
      m[s[i]] += 1;
      while (m.size() > k) {
        //cout << m.size() << endl;
        --m[s[left]];
        if (m[s[left]] == 0) {
          m.erase(s[left]);
        }
        ++left;
      }
      res = max(res, i - left + 1);
    }
    return res;
  }
};
