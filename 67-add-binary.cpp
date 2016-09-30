/*Given two binary strings, return their sum (also a binary string).

  For example,
  a = "11"
  b = "1"
  Return "100".
*/


class Solution {
public:
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int M = a.size();
    int N = b.size();
    int X = max(M, N);
    string res = "";
    int c = 0;
    for (int i = 0; i < X; ++i) {
      int v1 = i < M? a[i] - '0' : 0;
      int v2 = i < N? b[i] - '0' : 0;
      int sum = v1 + v2 + c;
      res += to_string(sum % 2);
      c = sum / 2;
    }
    if (c == 1) { //bug!! don't forget c==1 here, run testcase
      res += "1";
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
