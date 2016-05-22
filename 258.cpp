/*
  Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

  For example:

  Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

  Follow up:
  Could you do it without any loop/recursion in O(1) runtime?
*/

//http://www.cnblogs.com/grandyang/p/4741028.html

class Solution {
public:
  int addDigits(int num) {
    int tmp = sumDigits(num);
    while (tmp / 10 > 0) {
      tmp = sumDigits(tmp);
    }
    return tmp;
  }
    
  int sumDigits(int num) {
    int res = 0;
    while (num != 0) {
      int cur = num % 10;
      res += cur;
      num = num / 10;
    }
    return res;
  }
};
