/*
Given two strings S and T, determine if they are both one edit distance apart.
*/
//https://segmentfault.com/a/1190000003906621

class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    int m = s.size();
    int n = t.size();
    if (m == n) return isOneModified(s, t);
    if (m - n == 1) return isOneDeleted(s, t);
    if (n - m == 1) return isOneDeleted(t, s);
    return false;
  }
    
  bool isOneModified(const string& s, const string& t) {
    bool oneDiff = false;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != t[i]) {
	if (oneDiff) {
	  return false;
	}
	else
	  oneDiff = true;
      }
    }
    return oneDiff; //don't simply return true here
  }

  // s is longer than t.
  bool isOneDeleted(const string& s, const string& t) {
    int cur = 0;
    while (s[cur] == t[cur] && cur < t.size()) cur++;
    /*    cur += 1;
    while (cur < s.size()) { //compare with the pre one in t(t[cur-1])
      if (s[cur] != t[cur-1]) return false;
      cur++;
      }*/
    string subS = s.substr(cur+1);
    string subT = t.substr(cur);
    if (subS != subT) return false;
    return true;
  }
};
