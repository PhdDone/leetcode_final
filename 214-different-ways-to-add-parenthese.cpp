/*Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


  Example 1
  Input: "2-1-1".

  ((2-1)-1) = 0
  (2-(1-1)) = 2
  Output: [0, 2]


  Example 2
  Input: "2*3-4*5"

  (2*(3-(4*5))) = -34
  ((2*3)-(4*5)) = -14
  ((2*(3-4))*5) = -10
  (2*((3-4)*5)) = -10
  (((2*3)-4)*5) = 10
  Output: [-34, -14, -10, -10, 10]
*/


class Solution {
public:
  vector<int> diffWaysToCompute(string input) {
    vector<int> res;
    if (!input.size()) return res;
    int N = input.size();
    for (int i = 0 ; i < N; ++i) {
      if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
        auto left = diffWaysToCompute(input.substr(0, i));
        auto right = diffWaysToCompute(input.substr(i+1));
        for (auto num1 : left) {
          for (auto num2 : right) {
            if (input[i] == '+') {
              res.push_back(num1 + num2);
            } else if (input[i] == '-') {
              res.push_back(num1 - num2);
            } else if (input[i] == '*') {
              res.push_back(num1 * num2);
            }
          }
        }
      }
    }
    if (res.size() == 0) { //no + - * in the string, must be a number
      res.push_back(stoi(input));
    }
    return res;
  }
};
