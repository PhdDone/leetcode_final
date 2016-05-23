//Implement pow(x, n).

class Solution {
public:
  double myPow(double x, int n) {
    if(n>=0)
      return powPositive(x,n);
    else
      return 1/powPositive(x,-n);
  }
    
  double powPositive(double x, int n) {
    if(n==0) return 1; // base case
    double res = powPositive(x, n/2);
    res *= res;
    if(n%2) res *= x;
    return res;
  }
};
