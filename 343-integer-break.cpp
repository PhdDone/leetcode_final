
//http://www.jianshu.com/p/95782403f60e
/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.
*/

class Solution {
public:
  int integerBreak(int n) {
    vector<int> f(n + 1, 0);
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= n; i++) {
      for (int j = 1; j < i; j++) {
	f[i] = max(f[i], max(f[j], j) * max(f[i - j], i - j));
      }
    }
    return f[n];
  }
};
