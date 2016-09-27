/*
http://blog.csdn.net/pointbreak1/article/details/48596115

Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

  Examples:
  "123", 6 -> ["1+2+3", "1*2*3"]
    "232", 8 -> ["2*3+2", "2+3*2"]
    "105", 5 -> ["1*0+5","10-5"]
    "00", 0 -> ["0+0", "0-0", "0*0"]
    "3456237490", 9191 -> []
*/
//record last operand!!! when see *: result - lastOP + lastOP * curVaule

class Solution {
public:
  vector<string> addOperators(string num, int target) {
    long long lastOp = 0;
    long long curRes;
    string path = "";
    vector<string> res;
    int curIndex = 0;
    dfs(num, lastOp, curRes, path, res, target);
    return res;
  }

  void dfs(string num, long long lastOp, long long curRes, string path, vector<string>& res, int target) {
    if (num.size() == 0 && curRes == target) {
      res.push_back(path);
      return;
    }

    for (int i = 1; i <= num.size(); ++i) { // i <= num.size(), not only <
      string cur = num.substr(0, i);
      string rest = num.substr(i);
      if (cur.size() > 1 && cur[0] == '0') continue;
      long long curV = stoll(cur);
      if (path.size() == 0) {
        dfs(rest, curV, curV, cur, res, target); //!! curV curV cur
      } else {
        dfs(rest, curV, curRes + curV, path + "+" + cur, res, target); //update lastOp
        dfs(rest, -curV, curRes - curV, path + "-" + cur, res, target); //update lastOp to be negatev
        dfs(rest, lastOp*curV, curRes - lastOp + lastOp * curV, path + "*" + cur, res, target); //update to be *
      }
    }
  }
};
