/*you are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
  Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
*/

//http://www.cnblogs.com/jcliBlogger/p/4836567.html

//BFS queue
class Solution {
public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    if (rooms.empty()) return;
    int m = rooms.size(), n = rooms[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	if (!rooms[i][j]) {
	  queue<Grid> grids;
	  grids.push(Grid(i + 1, j, 1));
	  grids.push(Grid(i - 1, j, 1));
	  grids.push(Grid(i, j + 1, 1));
	  grids.push(Grid(i, j - 1, 1));
	  while (!grids.empty()) {
	    Grid grid = grids.front();
	    grids.pop();
	    int r = grid.r, c = grid.c, d = grid.d;
	    if (r < 0 || r >= m || c < 0 || c >= n || rooms[r][c] < d)
	      continue;
	    rooms[r][c] = d;
	    grids.push(Grid(r + 1, c, d + 1));
	    grids.push(Grid(r - 1, c, d + 1));
	    grids.push(Grid(r, c + 1, d + 1));
	    grids.push(Grid(r, c - 1, d + 1));
	  }
	}
      }
    }
  }
private:
  //self defined State structure in order to use queue
  struct Grid {
    int r, c, d;
    Grid(int _r, int _c, int _d) : r(_r), c(_c), d(_d) {}
  };
};
