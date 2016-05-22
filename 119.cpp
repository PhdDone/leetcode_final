/*Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

Show Tags
Show Similar Problems
*/


class Solution {
public:
  vector<int> getRow(int rowIndex) {
        
    if (rowIndex == 0) return vector<int>{1};
    vector<int> result = {1, 1};
    if (rowIndex == 1) return result;
    for (int i = 2; i <= rowIndex; ++i) {
      vector<int> next = {1};
      for (int i = 0; i < result.size() - 1; ++i) {
	next.push_back(result[i] + result[i+1]);
      }
      next.push_back(1);
      result = next;
    }
    return result;
  }
};
