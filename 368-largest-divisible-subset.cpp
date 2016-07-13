class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> res;
    int N = nums.size();
    if (N == 0) return res;

    vector<int> dp(N, 1);
    vector<int> index(N, -1);

    sort(nums.begin(), nums.end()); //remember to sort

    for (int i = 0; i < N; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          index[i] = j;
          //cuz we already check dp[j] + 1 > dp[i], means we should use j as the prev index for i
          //other shorter j' will not trigger the update of index[i]
        }
      }
    }

    int maxdp = 0;
    int k = 0;
    for (int i = 0; i < N; ++i) {
      if (dp[i] > maxdp) {
        maxdp = dp[i];
        k = i;
      }
    }

    for (int i = k; i != -1; i = index[i]) {
      res.push_back(nums[i]);
    }
    //return res; //reverse
    reverse(res.begin(), res.end());
    return res;
  }
};
