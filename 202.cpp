/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
*/

//http://yucoding.blogspot.com/2015/06/leetcode-question-happy-number.html


class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> path;
    int cur = n;
    while(true) {
      int next = 0;
      while(cur > 0) {
	next += (cur % 10) * (cur % 10);
	cur = cur/10;
      }
      cur = next;
      if (cur == 1) return true;
      if (path.find(cur) != path.end()) return false;
      path.insert(cur);
    }
        
  }
};
