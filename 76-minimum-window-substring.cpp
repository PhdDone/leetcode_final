/*Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

  For example,
  S = "ADOBECODEBANC"
  T = "ABC"
  Minimum window is "BANC".

  Note:
                  If there is no such window in S that covers all characters in T, return the empty string "".

  If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

  Show Company Tags
  Show Tags
  Show Similar Problems
  */


class Solution {
public:
  string minWindow(string s, string t) {
    int S = s.size();
    int T = t.size();
    unordered_map<char, int> expectedMap, windowMap;
    for (char c : t) {
      ++expectedMap[c];
      //cout << expectedMap[c] << endl;
    }
    int start = 0;
    int appeared = 0;
    int minLen = INT_MAX;
    int minStart = 0;
    for (int end = 0; end < S; ++end) {
      if (expectedMap[s[end]] > 0) {
        ++windowMap[s[end]];
        if (windowMap[s[end]] <= expectedMap[s[end]]) {
          ++appeared;
        }
      }
      if (appeared == T) { //once appeared == T, it will always to be T, start will only move
        //if the end have a same charactor with the start
        while (windowMap[s[start]] > expectedMap[s[start]] || expectedMap[s[start]] == 0) {
          --windowMap[s[start]];
          ++start;
        }
        if (end - start + 1 < minLen) {
          minLen = end-start + 1;
          minStart = start;
        }
      }
    }
    if (minLen == INT_MAX) return "";
    return s.substr(minStart, minLen);

  }
};
