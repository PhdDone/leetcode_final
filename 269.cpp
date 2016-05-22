/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
 */

class Solution {
public:
  string alienOrder(vector<string>& words) {
    string result;
    int maxWordLen = findMaxLen(words);
        
    for (int i = 0; i < maxWordLen; ++i) {
      for (auto word : words) {
	if (i >= word.size()) continue;
	else {
	  if (result.find(word[i]) == std::string::npos) {
	    result += word[i];
	  }
	}
      }

    }
    return result;
        
  }
    
  int findMaxLen(vector<string> const& words) {
    int maxLen = 0;
    for (auto word : words){
      maxLen= max(maxLen, int(word.size()));
    }
    return maxLen;
  }
};
