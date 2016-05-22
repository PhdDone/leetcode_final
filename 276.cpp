/*There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

  Note:
n and k are non-negative integers.
*/

class Solution {
public:
  int numWays(int n, int k) {
    if (n == 0 || k == 0) return 0;
    if (n == 1) return k;
    int d1[n] = {0};
    int d2[n] = {0};
    d1[0] = k; d1[1] = k;
    d2[0] = k; d2[1] = k*(k - 1);
    for (int i = 2; i < n; ++i) {
      d1[i] = d2[i-1];
      d2[i] = d1[i-1] * (k-1) + d2[i-1] * (k-1);
    }
    return d2[n-1] + d1[n-1];
  }
};

/*Need two one-dimensional array dp1 and dp2, dp1[i] means the number of solutions when the color of last two fences (whose indexes are i-1,i-2) are same. dp2[i] means the number of solutions when the color of last two fences are different.

So

dp1[i]=dp2[i-1],

dp2[i]=(k-1)(dp1[i-1]+dp2[i-1]) =(k-1)(dp2[i-2]+dp2[i-1])
*/
/*
I use s (same) to stand for the number of ways when the last two fences are painted with the same color (the last element of dp1 in the above post) and d (different) with d1 and d2 to stand for the last two elements of dp2 in the above post.

In each loop, dp1[i] = dp2[i - 1] turns into s = d2 and dp2[i] = (k - 1) * (dp2[i - 2] + dp2[i - 1]) becomes d2 = (k - 1) * (d1 + d2). Moreover, d1 needs to be set to the oldd2, which is recorded in s. So we have d1 = s.

Finally, the return value dp1[n - 1] + dp2[n - 1] is just s + d2.
*/
//https://leetcode.com/discuss/56146/dynamic-programming-c-o-n-time-o-1-space-0ms
