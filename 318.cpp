/*Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

														 Example 1:
														 Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
														 The two words can be "abcw", "xtfn".

														 Example 2:
														 Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
														 The two words can be "ab", "cd".

														 Example 3:
														 Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

class Solution {
public:
  int maxProduct(vector<string>& words) {
    vector<vector<bool>> map(words.size(), vector<bool> (26, false));
        
    int result = 0;
        
    //generate map
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < words[i].size(); ++j) {
	map[i][words[i][j] - 'a'] = true;
      }
    }
        
    for (int i = 0; i < words.size(); ++i) {
      for (int j = i+1; j < words.size(); ++j) {
	bool haveCommon = false;
	for (int k = 0; k < 26; ++k) {
	  if (map[i][k] && map[j][k]) {
	    haveCommon = true;
	    break;
	  }
	}
	if (!haveCommon)
	  result = max(result, int(words[i].size() * words[j].size()));
      }
    }
        
    return result;
  }
};
