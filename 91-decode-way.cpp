



class Solution {
public:
  int numDecodings(string s) {
    if(s.empty() || s[0]<'1' || s[0]>'9') return 0;
    vector<int> dp(s.size()+1,0);
    dp[0] = dp[1] = 1; //dp[i] means for len == i, how many ways to decode
    //dp[0] is 1 cuz when have input like 12, dp[2] += dp[0]
    for(int i=1; i<s.size(); i++) { //i is index, then length is i+1
      if(!isdigit(s[i])) return 0;
      int v = (s[i-1]-'0')*10 + (s[i]-'0');
      if(v<=26 && v>9) dp[i+1] += dp[i-1];
      if(s[i]!='0') dp[i+1] += dp[i];
      if(dp[i+1]==0) return 0; // input "100"
    }
    return dp[s.size()];
  }
};
