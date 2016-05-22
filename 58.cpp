/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

class Solution {
public:
  int lengthOfLastWord(string s) {
    stringstream ss(s);
    istream_iterator<string> iter(ss);
    istream_iterator<string> end;
    vector<string> tokens(iter, end);
    if (tokens.empty()) return 0;
    return tokens.back().size();
  }
};
