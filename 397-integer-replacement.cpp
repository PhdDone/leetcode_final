class Solution {
public:
  int integerReplacement(int n) {
    if (n == 1) return 0;
    if (n == 0) return 0;
    if (n % 2 == 0) {
      return dfs(n/2) + 1;
    } else {
      return min(dfs(long(n)+1), dfs(n-1)) + 1; //2147483647 == 2^31 - 1

  int dfs(long n) {
    if (n == 0 || n == 1) return 0;
    if (n % 2 == 0) return dfs(n/2) + 1;
    else return 1 + min(dfs(n+1), dfs(n-1));
  }
};
