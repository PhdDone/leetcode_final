/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
*/

//http://www.cnblogs.com/grandyang/p/5619296.html

class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num == 1) return true;
    for (int i = 2 ; i <= num / i; ++i) {
      if (num / i == i && num % i == 0) return true;
    }
    return false;
  }
};
