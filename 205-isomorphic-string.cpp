/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

Show Company Tags
Show Tags
Show Similar Problems
*/

#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> st;
    unordered_map<char, char> ts;
        
    int N = s.size();
    for (int i = 0; i < N; ++i) {
      auto iter = st.find(s[i]);
      if (iter != st.end()) {
	if (iter->second != t[i])
	  return false;
      }
      else {
	st[s[i]] = t[i]; //don't use ==
      }
    }
        
    for (int i = 0; i < N; ++i) {
      auto iter = ts.find(t[i]);
      if (iter != ts.end()) {
	if (iter->second != s[i])
	  return false;
      }
      else {
	ts[t[i]] = s[i]; //don't use ==
      }
    }
        
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isIsomorphic("aa", "bb");
  return 0;
}
