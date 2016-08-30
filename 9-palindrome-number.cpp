//Determine whether an integer is a palindrome. Do this without extra space.



class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false; // negative number is false
    int div = 1;
    while (x / div > 0) {
      div *= 10;
    }
    div /= 10;
    while (x > 0) {
      int l = x / div;
      int r = x % 10;
      if (l != r) return false;
      x = x % div;
      x = x / 10;
      div = div/100; // update div by dividing 100
    }
    return true;

  }
};
