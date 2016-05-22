
/*
Numbers can be regarded as product of its factors. For example,

  8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> results;
    if (n < 2) return results;
        
    vector<int> path;
        
    dfs(results, path, n, 2);
    return results;
  }
    
  void dfs(vector<vector<int>> &results, vector<int> &path, int n, int div) {
    if (n == 1) {
      if (path.size() > 1) { //not path.empty(), > 1, not >= because like 37
	results.push_back(path);
      }
      return;
    }
        
    for (int i = div; i <= n; ++i) { // i<=n, not i < n
      if (n % i == 0) {
	path.push_back(i);
	helper(results, path, n/i, i);
	path.pop_back();
      }
    }
  } 
};


int main() {
  Solution s;
  auto res = s.getFactors(8);
  return 0;
}
