/*Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

  Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/
//http://www.cnblogs.com/grandyang/p/4944875.html
class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> visited;
    queue<string> cur, next;
    bool found = false;
    cur.push(s);
    visited.insert(s);
    vector<string> res;
    while (!found && !cur.empty()) {
      while (!cur.empty()) {
        string curString = cur.front();
        //visited.insert(curString); //!! remeber to insert but not here!!
        cur.pop();
        if (isValid(curString)) {
          found = true;
          res.push_back(curString);
        } else {
          int N = curString.size();
          for (int i = 0; i < N; ++i) {
            if (curString[i] == '(' || curString[i] == ')') {
              string newString = curString.substr(0, i) + curString.substr(i+1, N - i - 1);
              if (visited.count(newString) == 0) {
                visited.insert(newString); //insert here!!
                next.push(newString);
              }
            }
          }
        }
      }
      // cur is empty
      swap(cur, next);
    }
    return res;
  }

  bool isValid(const string& s) { //how to know if a string is valid!!!
    int N = s.size();
    if (N == 0) return true;
    int cntLeft = 0;
    for (int i = 0; i < N; ++i) {
      if (s[i] == '(') {
        ++cntLeft;
      } else {
        if (s[i] == ')') {
          if (cntLeft == 0) return false;
          --cntLeft;
        }
      }
    }
    return cntLeft == 0; // check if cntLeft == 0!! not just return true
  }
};
