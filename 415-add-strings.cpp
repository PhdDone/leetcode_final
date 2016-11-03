/*
Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
Show Company Tags
Show Tags
Show Similar Problems
*/


class Solution {
public:
  string addStrings(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int N1 = num1.size();
    int N2 = num2.size();
    int N = max(N1, N2);
    string res;
    int c = 0;
    for (int i = 0; i < N; ++i) {
      int a = i >= N1? 0 : num1[i] - '0';
      int b = i >= N2? 0 : num2[i] - '0';
      int sum = c + a + b;
      res += to_string(sum % 10);
      c = sum/10;
    }
    if (c != 0) {
      res += to_string(c);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
