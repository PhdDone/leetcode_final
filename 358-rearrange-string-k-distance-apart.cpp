//http://www.cnblogs.com/grandyang/p/5586009.html
class Solution {
public:
  string rearrangeString(string str, int k) {
    unordered_map<char, int> m;
    if (k == 0) return str; // k == 0, return str
    string res = "";
    for (char c : str) {
      ++m[c];
    }
    priority_queue<pair<int, char>> q;
    for (const auto& p : m) {
      q.push(make_pair(p.second, p.first));
    }
    int len = str.size();

    while(!q.empty()) {
      int count = min(k, len);
      vector<pair<int, char>> tmp; //reset tmp
      for (int i = 0; i < count; ++i) {
        if (q.empty()) return "";
        auto x = q.top();
        q.pop();
        --x.first;
        res.push_back(x.second);
        --len; // update new len
        if (x.first > 0) tmp.push_back(x); //check x.first > 0
      }
      for (auto t : tmp) q.push(t);
    }
    return res;
  }
};
