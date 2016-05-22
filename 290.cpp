/*
Given a pattern and a string str, find if str follows the same pattern.

  Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

  Examples:
  pattern = "abba", str = "dog cat cat dog" should return true.
  pattern = "abba", str = "dog cat cat fish" should return false.
  pattern = "aaaa", str = "dog cat cat dog" should return false.
  pattern = "abba", str = "dog dog dog dog" should return false.
  Notes:
  You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/



class Solution {
public:
  bool wordPattern(string pattern, string str) {
    unordered_map<char, string> patternToString;
    unordered_map<string, char> stringToPattern;
        
    std::stringstream strstr(str);
    std::istream_iterator<std::string> it(strstr); //how to split strings in c++
    std::istream_iterator<std::string> end;
    vector<string> tokens(it, end);
        
    /* while(ss >> word)  
            strsplit.push_back(word);
    */
    int NT = tokens.size();
    int NP = pattern.size();
    if (NT != NP) return false;
        
    for (int i = 0 ; i < NT; ++i) {
      auto iter = patternToString.find(pattern[i]);
      if (iter != patternToString.end()) {
	auto candi = iter->second;
	if (candi != tokens[i]) return false;
      }
      else {
	patternToString[pattern[i]] = tokens[i];
      }
            
      auto iter2 = stringToPattern.find(tokens[i]);
      if (iter2 != stringToPattern.end()) {
	auto candi = iter2->second;
	if (candi != pattern[i]) return false;
      }
      else {
	stringToPattern[tokens[i]] = pattern[i];
      }
    }
    return true;
  }
};
