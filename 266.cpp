#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
  bool canPermutePalindrome(string s) {
    unordered_map<char, int> charCount;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      ++charCount[s[i]];
    }
    bool hasSingle = false;
    for (auto& c : charCount) {
      if (c.second % 2 == 1 && hasSingle == false) {
	hasSingle = true;
	continue;
      }
      if (c.second % 2 == 1 && hasSingle == true) {
	return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  string test = "as";
  cout << s.canPermutePalindrome(test);
  return 0;
}
