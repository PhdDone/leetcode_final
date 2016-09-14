/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
  bool isValid(string s) {
    int n = s.size();
    string left = "({[";
    string right = ")}]";
    stack<char> ps;
    for (int i = 0; i < n; ++i) {
      if (left.find(s[i]) != string::npos) { // string::npos
	ps.push(s[i]);
      }
      else {
	if (ps.empty()) return false; // check empty before pop!!!
	char top = ps.top();
	if (left.find(top) != right.find(s[i])) {
	  return false;
	}
	ps.pop(); // remeber to pop
      }
    }
    return ps.empty(); // check empty instead of return true
  }
};
