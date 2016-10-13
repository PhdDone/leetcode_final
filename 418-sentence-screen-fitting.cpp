//http://bookshadow.com/weblog/2016/10/09/leetcode-sentence-screen-fitting/

class Solution {
public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    int res = 0;
    int i = 0, j = 0;
    while (i < rows) {
      for (auto const& word : sentence) {
        //cout << word << endl;
        int N = word.size();
        if (N > cols) return 0;
        if (j == 0) {
          j += N;
        } else {
          int tmp = j + N + 1;
          if (tmp > cols) {
            ++i;
            //cout << word << endl;
            //cout << i << endl;
            if (i > rows) return res;
            j = N;
          } else {
            j = tmp;
          }
        }
      }
      ++res;
      //cout << "res " << res << endl;
    }
    return res;

  }
};
