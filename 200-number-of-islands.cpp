/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

  Example 1:

         11110
         11010
  11000
  00000
  Answer: 1

         Example 2:

         11000
         11000
  00100
  00011
  Answer: 3
*/

//set everyone to be zero when got 1

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
        
    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
	if (grid[i][j] == '1') {
	  count++;
	  dfs(grid, i, j);
	}
      }
    }
    return count;
  }
    
  void dfs(vector<vector<char>>& grid, int row, int col) {
    if (row < 0 || col < 0 || row == grid.size() || col == grid[row].size()) return;
        
    if (grid[row][col] == '1') {
      grid[row][col] = '0';
      dfs(grid, row + 1, col);
      dfs(grid, row - 1, col);
      dfs(grid, row, col + 1);
      dfs(grid, row, col - 1);
    }
    return;
  }
};

int numIslands(vector<vector<char>>& grid) {
  if(grid.empty()) return 0;
  int count = 0;
  for(int i = 0; i < grid.size(); ++i)
    for(int j = 0; j < grid[i].size(); ++j)
      if(grid[i][j] == '1'){
	++count;
	helper(grid, i, j);
      }
  return count;
}

void helper(vector<vector<char>>& grid, int row, int col){
  if(row < 0 || col < 0 || row == grid.size() || col == grid[row].size()) return ;
  if(grid[row][col] == '1') {
    grid[row][col] = '0';
    helper(grid, row - 1, col);
    helper(grid, row + 1, col);
    helper(grid, row, col - 1);
    helper(grid, row, col + 1);
  }
  return ;
}
