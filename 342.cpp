/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

  Example:
  Given num = 16, return true. Given num = 5, return false.

  Follow up: Could you solve it without loops/recursion?
*/



class Solution {
public:
  bool isPowerOfFour(int num) {
    if (num <= 0) return false; //consider all the cases <0, =0
    if (num == 1) return true;
        
    while (num > 1) {
      if (num % 4 != 0) return false;
      num /= 4;
    }
    return true;
  }
};


class Solution {
public:
  bool isPowerOfFour(int num) {
    return num<=0 ? false : fabs(log(num)/log(4) - (int)(log(num)/log(4))) < 0.0000001;
  }
};
