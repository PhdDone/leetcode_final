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
