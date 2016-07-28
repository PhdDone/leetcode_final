/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
  int reverse(int x) {
    // Write your code here
    int rst = 0;
        
    while(x != 0){
      int next_rst = rst * 10 + x % 10;
      x = x / 10;
      if(next_rst/10 != rst) { // test overflow!!
	rst  = 0;
	break;
      }
      rst = next_rst;
    }
    return rst;
  }
};
