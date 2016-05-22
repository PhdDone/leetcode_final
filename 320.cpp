//http://blog.csdn.net/hjf0416/article/details/50461816

//https://leetcode.com/discuss/76783/easiest-14ms-java-solution-beats-100%25

/*
Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
  ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/

class Solution {
public:
  vector<string> generateAbbreviations(string word) {
    vector<string> res;
    string path;
    dfs(res, path, word, 0, 0);
    return res;
  }
    
  void dfs(vector<string>& res, string path, string word, int cur, int num) {
    int len = path.size();
    if (cur == word.size()) {
      if(num != 0) //!! remeber to add num at the end
	path += to_string(num);
      res.push_back(path);
    } else{
      dfs(res, path, word, cur+1, num+1); //abbr word[cur]
            
      if(num != 0) {
	path += to_string(num);
      } //!! don't include dfs in if
      dfs(res, path + word[cur], word, cur + 1, 0); //not abbr word[cur], clear num
    }
    path = path.substr(0, len);
  }
};
