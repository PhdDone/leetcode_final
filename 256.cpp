#include <iostream>
#include <vector>

using namespace std;
//f[i][j] = min(f[i-1][(j+1) mod 3], f[i-1][(j+2) mod 3]) + f[i][j]
class Solution {
public:
  int minCost(vector<vector<int>>& costs) {
    if (costs.size() == 0) return 0;
    //if (costs.size() == 1) return std::min(std::min(costs[0][0], costs[0][1]), costs[0][2]);
    vector<vector<int>> f(costs.size(), vector<int>(costs[0].size()));
    int row = costs.size();
    int col = costs[0].size();

    f[0] = costs[0]; //remeber to initialize!!!

    for (int i = 1; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
	f[i][j] = std::min(f[i-1][(j+1) % col], f[i-1][(j+2) % col]) + costs[i][j];
      }
    }
    int min = std::min(f[row-1][0], f[row-1][1]);
    min = std::min(f[row-1][2], min);
    return min;
  }
};

int main() {
  vector<vector<int>> costs = { {1,2,3}, {4,5,6} };
  Solution s;
  std::cout << s.minCost(costs);

  return 0;
}
