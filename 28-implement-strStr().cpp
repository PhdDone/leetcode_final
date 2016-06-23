/*Implement strStr().

  Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.*/
class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
      return 0;
    }
    int N = haystack.size() - needle.size() + 1; //at the tail maintain at least needle.size() charactors
    for (int i = 0; i < N; ++i) {
      int j = i;
      int k = 0;
      while (j < haystack.size() && k < needle.size() && haystack[j] == needle[k]) {
	j++;
	k++;
      }
      if (k == needle.size()) return i;
    }
    return -1;
  }
};
