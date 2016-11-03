/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

  Example:
  Given "bcabc"
  Return "abc"

  Given "cbacdcbc"
  Return "acdb"
*/
  


class Solution {
public:
  string removeDuplicateLetters(string s) {
    int m[256] = {0};
    int visited[256] = {0};
    string res = "0";
    for (auto c : s) {
      ++m[c];
    }
    for (auto c : s) {
      --m[c]; //minus the freq first!!! don't put it after continue
      if (visited[c]) continue;

      while (res.back() > c && m[res.back()] > 0) { // m[res.back()] > 0 means we can see it after
        visited[res.back()] = 0;
        res.pop_back();
      }
      res.push_back(c);
      visited[c] = 1;
    }
    return res.substr(1);
  }
};
