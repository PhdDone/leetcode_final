//http://blog.csdn.net/yeqiuzs/article/details/52008544
//http://blog.csdn.net/zdavb/article/details/51933082
//http://www.cnblogs.com/grandyang/p/5677550.html
//http://blog.csdn.net/yeqiuzs/article/details/52008544

/*设dp[i][j]为i~j要保证赢的最多代价。 假设猜k值，若不对，则问题转化为猜1~k-1,k+1~n两个子问题，且猜k的结果会告诉我们需要猜哪个子问题，所以猜k要保证赢 最多需要money=k+max{dp[i][k-1],dp[k+1,j]}，则在i~j范围内存在某策略是最优的，则是猜测某个k需要的最少的money，为min{money} k属于[i,j]。*/
/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
  Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

  Game over. 8 is the number I picked.

  You end up paying $5 + $7 + $9 = $21.
  Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
*/

class Solution {
public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    return solver(dp, 1, n);
  }

  int solver(vector<vector<int>>& dp, int L, int R) {
    if (L >= R) return 0;
    if (dp[L][R]) return dp[L][R];
    dp[L][R] = INT_MAX;
    for (int i = L; i <= R; ++i) {
      dp[L][R] = min(dp[L][R], i + max(solver(dp, L, i-1), solver(dp, i+1, R)));
    }
    return dp[L][R];
  }
};
