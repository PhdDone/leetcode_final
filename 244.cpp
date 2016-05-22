/*This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

  For example,
  Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

  Given word1 = “coding”, word2 = “practice”, return 3.
  Given word1 = "makes", word2 = "coding", return 1.
*/


class WordDistance {
public:
  WordDistance(vector<string>& words) {
    int n = words.size();
    for (int i = 0; i < n; ++i) {
      matrix[words[i]].push_back(i);
    }
  }

  int shortest(string word1, string word2) {
    auto i1 = matrix[word1];
    auto i1n = i1.size();
    auto i2 = matrix[word2];
    auto i2n = i2.size();
    int minDis = INT_MAX;
        
    int i = 0; int j = 0;
    while (i < i1n && j < i2n) {
      minDis = abs(i1[i] - i2[j]) < minDis? abs(i1[i] - i2[j]) : minDis;
      if (i1[i] < i2[j]) ++i;
      else ++j;
    }
    return minDis;
  }
private:
  unordered_map<string, vector<int>> matrix;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
//time limitation exceed
class WordDistance {
public:
  WordDistance(vector<string>& words) {
    int n = words.size();
    for (int i = 0; i < n; ++i) {
      matrix[words[i]][words[i]] = 0;
      for (int j = i - 1; j >= 0; --j) {
	if (matrix[words[i]].find(words[j]) == matrix[words[i]].end()
	    || matrix[words[i]][words[j]] > i - j) {
	  matrix[words[i]][words[j]] = i - j;
	  matrix[words[j]][words[i]] = i - j;
	}
      }
    }
  }

  int shortest(string word1, string word2) {
    return matrix[word1][word2];
  }
private:
  unordered_map<string, unordered_map<string, int>> matrix;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
