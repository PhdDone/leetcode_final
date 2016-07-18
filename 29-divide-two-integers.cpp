/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution {
public:
  int divide(int dividend, int divisor) {

    long long b = divisor > 0? divisor : -(long long)divisor;
    long long a = dividend > 0? dividend : -(long long)dividend;

    // when divisor is -1 and dividend is INT_MIN
    long long ans = 0;
    while (a >= b) {
      long long c = b; //reset c every time c is larger than a;
      for (int i = 0; a >=c; ++i, c <<= 1) {
        a = a - c;
        ans += 1 << i;
      }
    }

    ans = ((divisor^dividend) >> 31) ? (-ans) : (ans);
    //cout << INT_MAX; //2147483647
    if (ans > INT_MAX) return INT_MAX;
    return ans;
  }
};
