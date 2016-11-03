

class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int N = A.size(); int M = B[0].size();
    vector<vector<int>> res(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
      for (int k = 0; k < A[0].size(); ++k) {
        if (A[i][k] != 0) {
          for (int j = 0; j < M; ++j) {
            if (B[k][j] != 0) {
              res[i][j] += A[i][k] * B[k][j];
            }
          }
        }
      }
    }
    return res;
  }
};

//res[0][0] = A[0][0]*B[0][0] + A[0][1] * B[0][1] + A[0][2]*B[2][0]
