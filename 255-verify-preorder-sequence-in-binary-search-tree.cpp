/*Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

  Follow up:
Could you do it using only constant space complexity?
*/

class Solution {
public:
  bool verifyPreorder(vector<int>& preorder) {
    int low = INT_MIN;
    stack<int> s;
    for (auto num : preorder) {
      if (num < low) return false;
      while (!s.empty() && num > s.top()) {
	low = s.top();
	s.pop();
      }
      s.push(num);
    }
    return true;
  }
};
