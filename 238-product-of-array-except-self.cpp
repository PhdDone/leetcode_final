/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

  Solve it without division and in O(n).

  For example, given [1,2,3,4], return [24,12,8,6].
*/

//http://fisherlei.blogspot.com/2015/10/leetcode-product-of-array-except-self.html
//maintain a products array, store the product of all the left nodes
//from right to left, multiply the products
class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> products;
    if (nums.size() == 0) return products;
    products.push_back(1);
    int product = 1;
    int N = nums.size();
    for (int i = 1; i < N; ++i) {
      product = product * nums[i-1];
      products.push_back(product);
    }
    product = 1;
    for (int i = N-2; i >= 0; --i) { //don't miss i = 0
      product = product * nums[i+1];
      products[i] = products[i] * product;
    }
    return products;
  }
};
