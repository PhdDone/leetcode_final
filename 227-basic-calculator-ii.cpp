// https://leetcode.com/discuss/39454/accepted-infix-postfix-based-solution-explaination-600ms

#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int calculate(string s) {
    string test = "10/1/2";
    auto res = infixToPostfix(test);
    for (auto r : res) {
      cout << r << endl;
    }
    cout << calculatePostfix(res) << endl;
    return 0;
  }

private:
  int rank(string op) {
    switch (op[0]) {
    case '+':
      return 1;
    case '-':
      return 1;
    case '*':
      return 2;
    case '/':
      return 2;
    }
    return 0;
  }
  bool isOperator(string s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
  }
  int calculatePostfix(const vector<string> &postfix) {
    stack<int> operands;
    int a = 0;
    int b = 0;
    int N = postfix.size();
    for (int i = 0; i < N; ++i) {
      if (isOperator(postfix[i])) {
        b = operands.top();
        operands.pop();
        a = operands.top();
        operands.pop();
        int c = 0;
        switch (postfix[i][0]) {
        case '+':
          c = a + b;
          break;
        case '-':
          c = a - b;
          break;
        case '*':
          c = a * b;
          break;
        case '/':
          c = a / b;
          break;
        }
        operands.push(c);
      } else {
        operands.push(stoi(postfix[i]));
      }
    }
    return int(operands.top());
  }
  vector<string> infixToPostfix(string s) {
    stack<string> operators;
    vector<string> postfix;

    s = s + "#"; // indicate the end of a number
    int N = s.size();
    for (int i = 0; i < N;) {
      if (s[i] >= '0' && s[i] <= '9') {
        stringstream number;
        number << s[i];
        ++i;
        while (i < N) {
          if (s[i] >= '0' && s[i] <= '9') {
            number << s[i];
            ++i;
          } else {
            postfix.push_back(number.str());
            break;
          }
        }
      } else {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
          string op = string(1, s[i]);
          while (!operators.empty() && rank(op) <= rank(operators.top())) { // move operators with higher rank to postfix
            postfix.push_back(operators.top());
            operators.pop();
          }
          operators.push(op);

          /*	  if (operators.empty()) {
            operators.push(op);
          }
          else {
            string top = operators.top();
            string current = string(1, s[i]);
            if (rank(current) > rank(top)) { //push to stack only if >, not =
              operators.push(current);
            }
            else {
              while (rank(top) >= rank(current)) { // >=, not >
                  postfix.push_back(top);
                  operators.pop();
                  if (operators.empty()) {
                    operators.push(current); //push here and set top to be empty
                    top = "";
                    break;
                  }
                  else {
                    top = operators.top();
                  }
                }
                //top is not empty, means we still need to push current operator
          into stack;
                if (top != "") {
                  operators.push(current);
                }
                }
                }*/
          i++;
        } else {
          i++;
        }
      }
    }
    while (!operators.empty()) {
      postfix.push_back(operators.top());
      operators.pop();
    }
    return postfix;
  }
};

int main() {
  Solution s;
  s.calculate("");
  return 0;
}
