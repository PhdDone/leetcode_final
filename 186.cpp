/*Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.
*/
class Solution {
public:
  void reverseWords(string &s) {
    reverse(s.begin(), s.end());

    for (string::iterator b = s.begin(), e = s.begin(); e <= s.end(); ++e) {
      if (e == s.end() || *e == ' ') {
	reverse(b, e);
	b = e + 1;
      }
    }
  }
};
