/*Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
  The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
  Note that you can only put the bomb at an empty cell.

  Example:
         For the given grid

  0 E 0 0
  E 0 W E
  0 E 0 0

  return 3. (Placing a bomb at (1,1) kills 3 enemies)
  */
class Solution {
public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    int R = grid.size();
    if (R == 0) return 0;
    int C = grid[0].size();
    vector<vector<int>> L2R(R, vector<int>(C, 0)), R2L = L2R, T2B = L2R, B2T = L2R;

    //left 2 right and right 2 left
    for (int i = 0; i < R; ++i) {
      //left 2 right
      for (int j = 0; j < C; ++j) {
        if (grid[i][j] == 'W') {
          L2R[i][j] = 0;
        }
        if (grid[i][j] == 'E') {
          L2R[i][j] = (j == 0)? 1 : L2R[i][j-1] + 1;
        }
        if (grid[i][j] == '0') {
          L2R[i][j] = (j == 0)? 0 : L2R[i][j-1];
        }
      }
      //right 2 left
      for (int j = C - 1; j >= 0; --j) {
        if (grid[i][j] == 'W') {
          R2L[i][j] = 0;
        }
        if (grid[i][j] == 'E') {
          R2L[i][j] = (j == C - 1)? 1 : R2L[i][j+1] + 1;
        }
        if (grid[i][j] == '0') {
          R2L[i][j] = (j == C - 1)? 0 : R2L[i][j+1];
        }
      }
    }

    for (int j = 0; j < C; ++j) {
      // top to bottom
      for (int i = 0; i < R; ++i) {
        if (grid[i][j] == 'W') {
          T2B[i][j] = 0;
        }
        if (grid[i][j] == 'E') {
          T2B[i][j] = (i == 0)? 1 : T2B[i-1][j] + 1;
        }
        if (grid[i][j] == '0') {
          T2B[i][j] = (i == 0)? 0 : T2B[i-1][j];
        }
      }
      // from bottom to top
      for (int i = R - 1; i >= 0; --i) {
        if (grid[i][j] == 'W') {
          B2T[i][j] = 0;
        }
        if (grid[i][j] == 'E') {
          B2T[i][j] = (i == R - 1)? 1 : B2T[i+1][j] + 1;
        }
        if (grid[i][j] == '0') {
          B2T[i][j] = (i == R - 1)? 0 : B2T[i+1][j];
        }
      }
    }

    int res = 0;

    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (grid[i][j] == '0')
          res = max(res, L2R[i][j] + T2B[i][j] + R2L[i][j] + B2T[i][j]);
      }
    }

    return res;

  }
};
