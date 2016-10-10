//http://www.cnblogs.com/grandyang/p/4985506.html
//https://leetcode.com/articles/range-sum-query-mutable/
/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

  The update(i, val) function modifies nums by updating the element at index i to val.
  Example:
  Given nums = [1, 3, 5]

  sumRange(0, 2) -> 9
  update(1, 2)
  sumRange(0, 2) -> 8
  Note:
  The array is only modifiable by the update function.
  You may assume the number of calls to update and sumRange function is distributed evenly.
  Show Tags
  Show Similar Problems
*/

class NumArray {
public:
  NumArray(vector<int> &nums) {
    int N = nums.size();
    bit.resize(N+1);
    num.resize(N+1);
    for (int i = 0; i < N; ++i) {
      update(i, nums[i]);
    }
  }

  void update(int i, int val) {
    int N = num.size();
    //int diff = val - num[i + 1];
    int diff = val - num[i];
    for (int j = i+1; j < N; j += (j & (-j))) {
      bit[j] += diff;
    }
    //num[i+1] = val;
    num[i] = val;
  }

  int sumRange(int i, int j) {
    return getSum(j+1) - getSum(i);
  }

  int getSum(int i) {
    int res = 0;
    for (int j = i; j > 0; j -= (j & -j)) {
      res += bit[j];
    }
    return res;
  }

  vector<int> bit;
  //vector<int> num;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
