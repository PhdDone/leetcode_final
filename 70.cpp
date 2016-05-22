/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Show Company Tags
Show Tags
*/


class Solution {
public:
  int climbStairs(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    int re[n] = {0};
    re[0] = 1;
    re[1] = 2;
    for (int i = 2; i < n; ++i) {
      re[i] = re[i-1] + re[i-2];
    }
    return re[n-1];
  }
};
