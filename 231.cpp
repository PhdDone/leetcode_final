/*Given an integer, write a function to determine if it is a power of two.*/


class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n < 1) return false;
    while (n > 1) {
      if (n % 2 != 0) return false;
      n = n / 2;
    }
    return true;
  }
};

//solution 2
class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return n == pow(2, round(log(n)/log(2)));
  }
};
