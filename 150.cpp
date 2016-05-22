/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

  Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<string> S;
    int result = 0;
    for (auto token : tokens) {
      if (isOperator(token)) {
	assert(S.size() >= 2);
	int v1 = stoi(S.top());
	S.pop();
	int v2 = stoi(S.top());
	S.pop();
	if (token == "*")
	  result = v2 * v1;
	if (token == "/")
	  result = v2 / v1;
	if (token == "+")
	  result = v2 + v1;
	if (token == "-")
	  result = v2 - v1;
	S.push(to_string(result));
      }
      else
	S.push(token);
    }
        
    if (!S.empty()) {
      result = stoi(S.top());
    }
    return result;
        
  }
    
  bool isOperator(const string& o) {
    return operators.find(o) != std::string::npos; //end of string: std::string::npos
  }
private:
  const string operators = "+-*/"; //can initialize member varialbles now
};
