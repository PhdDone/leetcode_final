#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    if (numRows == 0) return result;
        
    vector<int> preRow = {1};
    result.push_back(preRow);
        
    for (int i = 2; i <= numRows; ++i) {
      vector<int> preRowPad (preRow.size() + 2, 0);
      vector<int> curRow(i, 0);
      copy(preRow.begin(), preRow.end(), preRowPad.begin() + 1);
      for (int j = 0; j < curRow.size(); ++j) {
	curRow[j] = preRowPad[j] + preRowPad[j+1];
      }
      result.push_back(curRow);
      preRow = curRow;
    }
    return result;
  }
};

int main() {
  Solution s;
  s.generate(3);
  return 0;
}
