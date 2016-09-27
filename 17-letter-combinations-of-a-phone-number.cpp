/*Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
*/
class Solution {
public:
  vector<string> keyboard {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
  vector<string> letterCombinations(string digits) {
    vector<string> results;
    string path = "";
    int cur = 0;
    if (digits.size() == 0) return results;
    dfs(digits, cur, "", results);
    return results;
  }
    
  void dfs(const string& digits, int cur, string path, vector<string>& results) { //not the reference of path!! string& path, should be a copy, otherwise, need to pop_back to restore the path after recursion
    if (cur == digits.size()) {
      results.push_back(path);
      return;
    }
    for (auto c : keyboard[digits[cur] - '0']) {
      dfs(digits, cur + 1, path + c, results);
    }
  }
};
