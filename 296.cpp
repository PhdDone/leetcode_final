/*
A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

  For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
  The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

Show Hint 
Show Company Tags
Show Tags
Show Similar Problems
*/

/*
  similar with gradient decent, find the global minimun, randomly init then iterate until no change
*/


#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
  int minTotalDistance(vector<vector<int>>& grid) {
    vector<pair<int, int>> neighbors;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
	if (grid[i][j] == 1) {
	  neighbors.push_back(make_pair(i, j));
	}
      }
    }
    int ROW = grid.size();
    int COL = grid[0].size();
        
    int row = 0;
    int col = 0;
        
    bool changed = true;
    int result = MDistance(row, col, neighbors);

    while (changed) {
      int curMin = result;
      int minCol = col;
      int minRow = row;
      //left
      if (col - 1 >= 0) {
	int left = MDistance(row, col - 1, neighbors);
	if (curMin > left) {
	  curMin = left;
	  minCol = col - 1;
	  minRow = row;
	}
      }
      //right
      if (col + 1 < COL) {
	int right = MDistance(row, col + 1, neighbors);
	if (curMin > right) {
	  curMin = right;
	  minCol = col + 1;
	  minRow = row;
	}
      }
            
      //down
      if (row + 1 < ROW) {
	int down = MDistance(row + 1, col, neighbors);
	if (curMin > down) {
	  curMin = down;
	  minRow = row + 1;
	  minCol = col;
	}
      }
            
      //up
      if (row - 1 >= 0) {
	int up = MDistance(row - 1, col, neighbors);
	if (curMin > up) {
	  curMin = up;
	  minRow = row - 1;
	  minCol = col;
	}
      }
      if (row == minRow && col == minCol) {
	changed = false;
      }
      else {
	result = curMin;
	row = minRow;
	col = minCol;
      }
    }
    return result;
  }
    
  float MDistance(int row, int col, vector<pair<int, int>> nei) {
    float d = 0;
    for (auto p : nei) {
      d = d + std::abs(float(row - p.first)) + std::abs(float(col - p.second));
    }
    return d;
  }
};

int main(){
  Solution s;
  vector<vector<int>> grid {
    {1,0,0,0,1}
    ,{0,0,0,0,0}
    ,{0,0,1,0,0}
  };
  cout << s.minTotalDistance(grid);
  return 0;
}
