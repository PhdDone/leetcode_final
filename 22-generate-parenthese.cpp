/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

  For example, given n = 3, a solution set is:

  [
   "((()))",
   "(()())",
   "(())()",
   "()(())",
     "()()()"
   ]
*/
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    int l = 0;
    int r = 0;
    string path;
    vector<string> res;
    helper(res, path, l, r, n);
    return res;
  }

  void helper(vector<string>& res, string& path, int l, int r, int n) {
    if (l == n) {
      string tmp = path; //make a copy!! otherwise when return we can not recover the enviroment!!
      tmp.append(n - r, ')'); //append!!
      res.push_back(tmp);
      return;
    }

    path.push_back('(');
    helper(res, path, l + 1, r, n);
    path.pop_back();

    if (l > r) {
      path.push_back(')');
      helper(res, path, l, r + 1, n);
      path.pop_back();
    }
  }
};
