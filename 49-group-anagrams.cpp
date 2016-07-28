/*Given an array of strings, group anagrams together.

  For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
  Return:

  [
   ["ate", "eat","tea"],
   ["nat","tan"],
     ["bat"]
   ]
    Note: All inputs will be in lower-case.
*/  

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<int>> wordToIndex;

    int N = strs.size();

    for (int i = 0; i < N; ++i) {
      string s = strs[i];
      sort(s.begin(), s.end());
      if (wordToIndex.count(s) == 0) {
        wordToIndex[s] = vector<int>{i};
      } else {
        wordToIndex[s].push_back(i);
      }
    }

    for (auto w : wordToIndex) {
      vector<string> r;
      for (auto i : w.second) {
        r.push_back(strs[i]);
      }
      res.push_back(r);
    }
    return res;
  }
};
