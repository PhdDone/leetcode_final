/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

  You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
  After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
  Example:

  prices = [1, 2, 3, 0, 2]
maxProfit = 3
  transactions = [buy, sell, cooldown, buy, sell]
*/
//https://www.hrwhisper.me/leetcode-best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int N = prices.size();
    if (N < 2) return 0;
    vector<int> buy(N, 0);     //maintain two arraies: buy and sell
    vector<int> sell(N, 0);
    //buy record the most profit to buy at day i
    //sell record the most profit to sell at day i
    buy[0] = -prices[0];
    buy[1] = max(-prices[0], -prices[1]);
    sell[1] = max(0, prices[1] - prices[0]);
    for (int i = 2; i < N; ++i) {
      buy[i] = max(buy[i-1], sell[i-2]-prices[i]); //update function use sell[i-2] because we can't sell on day i-1
      sell[i] = max(sell[i-1], buy[i-1] + prices[i];)
    }
    return sell[N-1];
  }
};

/* example
price: [1, 2, 4]
buy: [-1, -1, -4]
sell: [0, 1, 3]
*/
