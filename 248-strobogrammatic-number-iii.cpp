//https://leetcode.com/problems/strobogrammatic-number-iii/

class Solution {
public:
  Solution() {
    mp = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}}; //numbers combination
  }
    
  int strobogrammaticInRange(string low, string high) {
    int ans = 0, l = low.length(), u = high.length();
    for (int i = l; i <= u; i++) {
      string temp(i, ' '); //fill the numbers from mp from left and right to the middle
      strobogrammaticCount(temp, ans, low, high, 0, i - 1);
    }
    return ans;
  }
private:
  unordered_map<char, char> mp;
  void strobogrammaticCount(string temp, int& ans, string& low, string& high, int lo, int hi) {
    if (lo > hi) {
      if ((temp[0] != '0' || temp.length() == 1) && less(low, temp) && less(temp, high))
	ans++;
      return;
    }
    for (auto m : mp) {
      temp[lo] = m.first;
      temp[hi] = m.second;
      if ((lo == hi && m.first == m.second) || lo < hi) //if lo == hi, means the middle of that number is odd
	strobogrammaticCount(temp, ans, low, high, lo + 1, hi - 1);
    }
  }
  bool less(string& s, string& t) {
    int m = s.length(), n = t.length(), i;
    if (m != n) return m < n;
    for (i = 0; i < m; i++)
      if (s[i] == t[i]) continue;
      else break;
    return i == m || s[i] < t[i];
  }
};
