/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

  Example:
  Given a = 1 and b = 2, return 3.
*/
  


class Solution {
public:
  int getSum(int a, int b) {
    int carry = 0;
    int cur = 0;
    int res = 0;
    while (cur < 32) {
      //cout << res << endl;
      int mask = 1 << cur;
      int x = (a & mask) >> cur; // use bitwise &
      int y = (b & mask) >> cur;
      if (x && y) { //use x and y, not a, b
        res |= carry << cur;
        carry = 1;
      }
      if (x || y) {
        if (carry) {
          carry = 1;
        } else {
          res |= 1 << cur;
          cout << res << endl;
          carry = 0;
        }
      }
      if (!x && !y) {
        res |= carry << cur;
        carry = 0;
      }
      ++cur;
    }
    return res;
  }
};
