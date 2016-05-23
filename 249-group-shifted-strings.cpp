/*Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
  Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

  For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
											   Return:

[
 ["abc","bcd","xyz"],
 ["az","ba"],
 ["acef"],
 ["a","z"]
]
*/

/**
 * every charactor has the same distance with the first charator
 **/

class Solution {
public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    unordered_map<string, vector<string>> d;
    for (auto word : strings) {
      string key = "";
      for (auto j : word) { //key is not the string, is the distance between cur character and first character
	key += to_string((j-word[0] + 26) % 26) + " "; //!!! or just keep negative
      }
      if (d.find(key) != d.end()) {
	d[key].push_back(word);
      }
      else {
	vector<string> result;
	result.emplace_back(word);
	d.insert(pair<string, vector<string>>(key, result));
      }
    }
        
    vector<vector<string>> results;
    for (auto i = d.begin(); i != d.end(); ++i) {
      sort(i->second.begin(), i->second.end());
      results.push_back(i->second);
    }
    return results;
  }

};
