/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  string reverseVowels(string s) {
    string vowels = "aeiou";
    int start = 0;
    int end = s.size() - 1;
    while (start < end) {
      while (start < end && vowels.find(tolower(s[start])) == string::npos) //to lowercase
	++start;
      while (end > start && vowels.find(tolower(s[end])) == string::npos))
	--end;
      if (start < end) {
	auto tmp = s[start];
	s[start] = s[end];
	s[end] = tmp;
	++start;
	--end;
      }
    }
    return s;
  }
};

int main() {
  Solution s;
  string test = "hello";
  cout << s.reverseVowels(test) << endl;
  return 0;
}
