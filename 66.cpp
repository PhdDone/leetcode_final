/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Show Company Tags
Show Tags
Show Similar Problems
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    if (n == 0) return vector<int>{1}; //check doube equal
    reverse(digits.begin(), digits.end());
    int c = 0;
    int sum = digits[0] + 1;
    c = sum / 10;
    digits[0] = sum % 10;
    int i = 1;
    while (i < n) {
      sum = digits[i] + c;
      c = sum/10;
      digits[i] = sum % 10;
      ++i;
    }
    if (c > 0) {
      digits.push_back(c);
    }
    reverse(digits.begin(), digits.end());
    return digits;
  }
};

int main() {
  Solution s;
  vector<int> test {9, 9};
  auto result = s.plusOne(test);
  for (auto num : result) {
    cout << num << endl;
  }
  return 0;
}

