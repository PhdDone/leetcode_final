/*You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

  Each 0 marks an empty land which you can pass by freely.
  Each 1 marks a building which you cannot pass through.
  Each 2 marks an obstacle which you cannot pass through.
  For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

  1 - 0 - 2 - 0 - 1
  |   |   |   |   |
  0 - 0 - 0 - 0 - 0
  |   |   |   |   |
  0 - 0 - 1 - 0 - 0
  The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

  Note:
  There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/



class Solution {
public:

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  int shortestDistance(vector<vector<int>>& grid) {
    int R = grid.size();
    if (R == 0) return 0;
    int C = grid[0].size();

    vector<vector<int>> visited(R, vector<int>(C, 0));
    vector<vector<int>> res(R, vector<int>(C, 0));
    vector<vector<int>> reached(R, vector<int>(C, 0));
    //int visitVal = 0; //try to visit this value, after visit, --visited[i][j];

    int totalOne = 0;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (grid[i][j] == 1) {
          ++totalOne;
          //cout << i << " " << j << endl;
          bfs(grid, i, j, R, C, visited, res, reached);
        }
      }
    }

    int minDis = INT_MAX;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (grid[i][j] == 0 && reached[i][j] == totalOne) { //should reach every 1s !!!!
          //cout << i << " " << j << endl;
          //cout << res[i][j] << endl;
          minDis = min(minDis, res[i][j]);
        }
      }
    }
    minDis = minDis == INT_MAX? -1: minDis;
    return minDis == 0? -1 : minDis;
  }

  void bfs(const vector<vector<int>>& grid, int xx, int yy, int R, int C, vector<vector<int>> visited, vector<vector<int>>& res, vector<vector<int>>& reached) {
    queue<pair<int,&& !visited[nx][ny]) {
    visited[nx][ny] = true;
    ++reached[nx][ny];
    curRes[nx][ny] += curRes[x][y] + 1;
    //if (nx == 1 && ny == 2) {
    //    cout << res[x][y] << endl;
    //   cout << res[nx][ny] << endl;
    //}
    q.push(make_pair(nx, ny));
  }
}
  }
for (int i = 0; i < R; ++i) {
  for (int j = 0; j < C; ++j) {
    res[i][j] += curRes[i][j];
  }
 }
}
};
