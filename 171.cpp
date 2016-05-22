/*Given a column title as appear in an Excel sheet, return its corresponding column number.

  For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

class Solution {
public:
  int titleToNumber(string s) {
    int n = s.size();
    int c = pow(26, n-1);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      res += (s[i] - 'A' + 1) * c;
      c /= 26;
    }
    return res;
  }
};
