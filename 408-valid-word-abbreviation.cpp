/*
Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Example 1:
Given s = "internationalization", abbr = "i12iz4n":

Return true.
Example 2:
Given s = "apple", abbr = "a2e":

Return false.
*/


class Solution {
public:
  bool validWordAbbreviation(string word, string abbr) {
    int Nw = word.size();
    int Na = abbr.size();

    int curW = 0, curA = 0;

    while (curW < Nw && curA < Na) {
      int diff = abbr[curA] - '0';
      if (diff > 0 && diff <= 9) {
        int end = curA;
        for (int i = curA; i < Na; ++i) {
          int d2 = abbr[i] - '0';
          if (d2 >= 0 && d2 <= 9) {
            end = i;
          } else {
            break;
          }
        }
        int num = stoi(abbr.substr(curA, end - curA + 1));
        curA = end + 1;
        curW += num;
      } else {
        if (word[curW] != abbr[curA]) {
          return false;
        } else {
          ++curW;
          ++curA;
        }
      }
    }

    return curW == Nw && curA == Na;
  }
};
