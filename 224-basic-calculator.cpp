//http://blog.welkinlan.com/2015/09/06/basic-calculator-i-ii-leetcode-java/

/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

  You may assume that the given expression is always valid.

  Some examples:
"1 + 1" = 2
  " 2-1 + 2 " = 3
  "(1+(4+5+2)-3)+(6+8)" = 23
*/

// use a stack to record the current sign in current cell()
// for (1 + 4), when reach 1, stack.top() == 1
// 3-(1+4), when reach 1, stack.top() == -1
// 5-(2-(1+4)), when reach 1, stack.top() == 1

class Solution {
public:
  int calculate(string s) {
    stack<int> S;
    S.push(1);
    int res = 0;
    int sign = 1;
    int N = s.size();
    for (int i = 0; i < N; ++i) {
      char c = s[i];
      if (c == '+' || c == '-') {
        sign = c == '+' ? 1 : -1;
      } else if (c == '(') {
        S.push(S.top() * sign);
        sign = 1; // the default sign of the first number after '(' should be 1
      } else if (c == ')') {
        S.pop(); // pop the top, don't need to store the sign anymore
      } else if (c >= '0' && c <= '9') {
        int num = c - '0';
        int j = i + 1;
        while (s[j] >= '0' && s[j] <= '9') {
          num = num * 10 + s[j] - '0';
          ++j;
        }
        i = j - 1;
        res = res + num * sign * S.top();
      }
    }
    return res;
  }
};
