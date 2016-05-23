/*Given an integer, write a function to determine if it is a power of two.*/

//http://www.cnblogs.com/grandyang/p/4623394.html


//only has one 1
class Solution {
public:
  bool isPowerOfTwo(int n) {
    int cnt = 0;
    while (n > 0) {
      cnt += (n & 1);
      n >>= 1; //use >>=, not just >>
    }
    return cnt == 1;
  } 
};

class Solution {
public:
  bool isPowerOfTwo(int n) {
    return (n > 0) && (!(n & (n - 1)));
  } 
};

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
