/*
  Given two strings s and t, write a function to determine if t is an anagram of s.

  For example,
  s = "anagram", t = "nagaram", return true.
  s = "rat", t = "car", return false.
*/

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;
    unordered_map<char, int> mapa;
    for (char& ch : s)
      mapa[ch]++;
    for (char& ch : t)
      mapa[ch]--;
    for (auto it = mapa.begin(); it != mapa.end(); it++)
      if ((*it).second != 0)
	return false;
    return true;
  }
};
