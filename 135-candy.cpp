/*There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

class Solution {
public:
  int candy(vector<int>& ratings) {
    int N = ratings.size();
    vector<int> lc(N, 1);
    vector<int> rc(N, 1);
    for (int i = 1; i < N; ++i) {
      if (ratings[i] > ratings[i-1]) {
        lc[i] = lc[i-1] + 1;
      }
    }
    for (int i = N - 2; i >=0; --i) {
      if (ratings[i] > ratings[i+1]) {
        rc[i] = rc[i+1] + 1;
      }
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
      res += max(rc[i], lc[i]);
    }
    return res;
  }
};
