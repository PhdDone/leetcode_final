class Solution {
public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    unordered_map<string, vector<int>> wordsMap;
    for (int i = 0, j = words.size(); i < j; ++i) {
      wordsMap[words[i]].push_back(i);
    }
        
    vector<int> indexes1 = wordsMap[word1];
    vector<int> indexes2 = wordsMap[word2];
        
    int min = INT_MAX;
    for (auto i : indexes1) {
      for (auto j : indexes2) {
	min = abs(i - j) < min? abs(i-j) : min;
      }
    }
    return min;
  }
};


//solution 2 O(n)
class Solution {
public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    int res = INT_MAX;
    int w1 = -1;
    int w2 = -1;
    int N = words.size();
        
    for (int i = 0; i < N; ++i) {
      if (words[i] == word1) {
	w1 = i;
	if (w2 != -1) {
	  res = min(res, w1 - w2); 
	}
      }
            
      if (words[i] == word2) {
	w2 = i;
	if (w1 != -1) {
	  res = min(res, w2 - w1);
	}
      }
    }
    return res;
  }
};
