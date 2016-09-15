/*Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

  F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

  Calculate the maximum value of F(0), F(1), ..., F(n-1).

  Note:
  n is guaranteed to be less than 105.
*/
class Solution {
public:
  int maxRotateFunction(vector<int>& A) {
    int sumA = accumulate(A.begin(), A.end(), 0);

    int N = A.size();
    int x_prev = 0;
    for (int i = 0; i < N; ++i) {
      x_prev += i * A[i];
    }
    int maxF = x_prev;

    for (int i = 1; i < N; ++i) {
      int x_i = x_prev - sumA + N * A[i-1];
      maxF = (x_i > maxF)? x_i : maxF;
      x_prev = x_i;
    }
    return maxF;
  }
};

//x_i = x_prev - sumA + N*A[i-1]
