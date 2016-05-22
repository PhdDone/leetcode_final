/*
 *The set [1,2,3,…,n] contains a total of n! unique permutations.
 *Given n and k, return the kth permutation sequence.
 */

#include <iostream>

#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// time limit exceeded
class Solution {
public:
  string getPermutation(int n, int k) {
    vector<int> path;
    for (int i = 1; i <= n; ++i) {
      path.push_back(i);
    }
    vector<vector<int>> results;
        
    helper(results, path, 0);
        
    stringstream ss;
    copy( results[k].begin(), results[k].end(), ostream_iterator<int>(ss));
    string s = ss.str();
    return s;
  }
    
  void helper(vector<vector<int>> &results, vector<int> &path, int cur) {
    if (cur == path.size()) {
      results.push_back(path);
      return;
    }
        
    for (int i = cur; i < path.size(); ++i) {
      swap(path[i], path[cur]);
      helper(results, path, cur + 1); //pass cur + 1, not i + 1
      swap(path[cur], path[i]);
    }
  }
};


int main() {
  Solution s;
  auto b = s.getPermutation(3, 5);
  cout << b;
  return 0;
}
