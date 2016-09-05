/*Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
  such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
                                                       Your algorithm should run in O(n) time complexity and O(1) space complexity.
                                                       
                                                       Examples:
                                                       Given [1, 2, 3, 4, 5],
                                                       return true.

                                                       Given [5, 4, 3, 2, 1],
                                                       return false.
*/


//http://www.cnblogs.com/grandyang/p/5194599.html

class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int m1 = INT_MAX; //m1 < m2
    int m2 = INT_MAX;
    for (int num : nums) {
      if (num <= m1) {
        m1 = num;   // m1 is the smallest
      } else {
        if (num <= m2) {
          m2 = num;  // m2 is the second smallest
        } else {
          return true;
        }
      }
    }
    return false;
  }
};
