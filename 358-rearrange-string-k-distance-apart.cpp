/*
Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
str = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.
Example 2:
str = "aaabc", k = 3 

Answer: ""

It is not possible to rearrange the string.
Example 3:
str = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.

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
