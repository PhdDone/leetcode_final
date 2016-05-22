/*
Given an integer, write a function to determine if it is a power of three.

  Follow up:
Could you do it without using any loop / recursion?
*/

class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n < 1) return false; //n < 1, not zero
    while (n > 1) { //n > 1
      if (n % 3 != 0) return false;
      n = n/3;
    }
    return true;
  }
};


//solution2 log
//https://www.hrwhisper.me/leetcode-power-of-three/

class Solution {
public:
  bool isPowerOfThree(int n) {
    return n <= 0 ? false : n == pow(3, round(log(n) / log(3))); //round half adjusting
  }
};
