/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

  Example:
                                                                                                                                                            Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/
class Solution {
public:
  int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end());
    int N = envelopes.size();
    //for (auto e : envelopes) {
    //    cout << e.first << " " << e.second << endl;
    //}
    vector<int> dp(N, 1);
    int res = N > 0? 1 : 0;
    for (int i = 0; i < N; ++i) {
      //      int tmp = 0; //dp back search and get a max, then add the max to dp[i]
      for (int j = i - 1; j >=0; --j) {
        if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second) {
          //tmp = max(tmp, dp[j]);
          dp[i] = max(dp[i], dp[j]+1);
        }
      }
      //dp[i] += tmp;
      res = max(dp[i], res);
    }
    return res;

  }
};
