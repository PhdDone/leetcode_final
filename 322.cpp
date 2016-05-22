#include <iostream>
#include <vector>

using namespace std;

class Solution {
  /*
[186,419,83,408]
6249
  fails, return -1, should return 20??*/
public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    if (coins.size() == 0 && amount != 0) return -1;
        
    int n = coins.size();
    int curCoin = n - 1;
    int numCoins = 0;
        
    return helper(coins, curCoin, amount);
  }
    
  int helper(vector<int>& coins, int curCoin, int amountLeft) {
        
    if (amountLeft == 0) {
      return 0;
    }
    // can't make change
    if(curCoin < 0) {
      return -1;
    }
        
    for (int i = curCoin; i >= 0 ; --i) {
      int maxCurCoin = amountLeft / coins[i];  // coins[1] != 0
      for (int j = maxCurCoin; j >=0; --j) {
	int moreCoinsNeed = helper(coins, --curCoin, amountLeft - j * coins[i]);
	if (moreCoinsNeed != -1)
	  return moreCoinsNeed + j;
	else
	  return -1;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<int> coins{1};
  cout << s.coinChange(coins, 1);
  return 0;
}


//s2
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (auto coin : coins) {
      for (int i = coin; i <= amount; ++i) { //iterate through coin to amount, find the min change for each amount
	// every node in dp is the minus number of coins that used to reach that node
	if (dp[i-coin] != INT_MAX) {
	  dp[i] = min(dp[i], dp[i - coin] + 1);
	}
      }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};
//https://www.hrwhisper.me/leetcode-coin-change/
