/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

  For example, given the array [2,3,-2,4],
  the contiguous subarray [2,3] has the largest product = 6.
*/

//http://bangbingsyb.blogspot.com/2014/11/leetcode-maximum-product-subarray.html

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int N = nums.size();
    if (N == 0) return 0;
    int curMin, curMax, res; //maintain a curMin and curMax
    res = curMin = curMax = nums[0];
        
    for (int i = 1; i < N; ++i) {
      int temp = curMax;
      curMax = max(max(curMax * nums[i], curMin * nums[i]), nums[i]);
      curMin = min(min(temp * nums[i], curMin * nums[i]), nums[i]);
      res = max(res, curMax);
    }
    return res;
  }
};
