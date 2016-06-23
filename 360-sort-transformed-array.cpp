/*
Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
*/

class Solution {
public:
  vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    int N = nums.size();
    vector<int> res(N, 0);
    int i = 0;
    int j = N - 1;
    int idx = a > 0? N - 1 : 0;
    while (i <= j) {
      if (a > 0) {
	if (cal(a, b, c, nums[i]) > cal(a, b, c, nums[j])) {
	  res[idx] = cal(a, b, c, nums[i]);
	  i++;
	} else {
	  res[idx] = cal(a, b, c, nums[j]);
	  j--;
	}
	idx--;
      } else {
	if (cal(a, b, c, nums[i]) < cal(a, b, c, nums[j])) {
	  res[idx] = cal(a, b, c, nums[i]);
	  i++;
	} else {
	  res[idx] = cal(a, b, c, nums[j]);
	  j--;
	}
	idx++;
      }
    }
    return res;
  }
    
  int cal(int a, int b, int c, int x) {
    return a * x * x + b * x + c;
  }
};
