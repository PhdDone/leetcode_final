/*38 count and say http://bangbingsyb.blogspot.com/2014/11/leetcode-count-and-say.html
165 compare version number http://yucoding.blogspot.com/2015/03/leetcode-question-compare-version.html
230 remove linked list element 
240 search a 2d matrix ii http://bookshadow.com/weblog/2015/07/23/leetcode-search-2d-matrix-ii/
347 top k frequent elements https://www.hrwhisper.me/leetcode-top-k-frequent-elements/
351 android unlock patterns http://www.cnblogs.com/grandyang/p/5541012.html
*/

#include<iostream>
#include<vector>

using namespace std;

class A
{
public:
  void foo()
  {
    printf("1\n");
  }
  virtual void fun()
  {
    printf("2\n");
  }
};
class B : public A
{
public:
  void foo()
  {
    printf("3\n");
  }
  void fun()
  {
    printf("4\n");
  }
};


class Solution {
public:
  bool isMatch(const string& s, const string& p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1,false));
    dp[0][0] = true;

    for(int i=0; i<=m; i++) {
      for(int j=1; j<=n; j++) {
        if(p[j-1]!='.' && p[j-1]!='*') {
          if(i>0 && s[i-1]==p[j-1] && dp[i-1][j-1])
            dp[i][j] = true;
        }
        else if(p[j-1]=='.') {
          if(i>0 && dp[i-1][j-1])
            dp[i][j] = true;
        }
        else if(j>1) {  //'*' cannot be the 1st element
          if(dp[i][j-1] || dp[i][j-2])  // match 0 or 1 preceding element
            dp[i][j] = true;
          else if(i>0 && (p[j-2]==s[i-1] || p[j-2]=='.') && dp[i-1][j]) // match multiple preceding elements
            dp[i][j] = true;
        }
      }
    }
    for (int i = 0; i < m + 1; ++i) {
      for (int j = 0; j < n + 1; ++j) {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
    cout << dp[m][n] << endl;
    return dp[m][n];
  }
};

int main(void)
{
  Solution s;
  string a = "aaaaaa";
  string b = "a*";
  s.isMatch(a, b);
  return 0;
}
