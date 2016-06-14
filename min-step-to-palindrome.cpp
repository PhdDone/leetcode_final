int minStepToPal(string &str) {
  if (str.empty())
    return 0;
    
  vector<vector<int>> dp(str.length(), vector<int>(str.length()));
  for (int i = str.length() - 1; i >= 0; --i) {
    for (int j = i; j < str.length(); ++j) {
      if (i == j)
	dp[i][j] = 0;
      else if (i + 1 == j)
	dp[i][j] = (str[i] == str[j] ? 0 : 1);
      else {
	if (str[i] == str[j])
	  dp[i][j] = dp[i + 1][j - 1];
	else
	  dp[i][j] = min(dp[i + 1][j - 1], min(dp[i][j - 1], dp[i + 1][j])) + 1;
      }
    }
  }
  return dp[0][str.length() - 1];
}
