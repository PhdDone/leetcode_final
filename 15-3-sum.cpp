/*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

  Note: The solution set must not contain duplicate triplets.

  For example, given array S = [-1, 0, 1, 2, -1, -4],

  A solution set is:
  [
   [-1, 0, 1],
   [-1, -1, 2]
   ]
*/

// O(n^2)
// fix the first element first, go over the rest
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> allRes;
    int N = nums.size();
    if (N == 0) return allRes;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < N - 2; ++i) {
      int left = i + 1;
      int right = N - 1;
      if ( i > 0 && nums[i] == nums[i - 1]) continue; // skip dup for the first element
      while (left < right) {
        if (nums[i] + nums[left] + nums[right] == 0) {
          vector<int> res {nums[i], nums[left], nums[right]};
          allRes.push_back(res);
          left++; // remeber to update left and right here!!!
          right--;
          while (nums[right] == nums[right + 1]) --right; // skip dup for the second element
          while (nums[left] == nums[left - 1]) ++left;    // skip dup for the third element
        } else {
          if (nums[i] + nums[left] + nums[right] > 0) {
            --right;
            while (nums[right] == nums[right + 1]) --right;
          } else {
            ++left;
            while (nums[left] == nums[left - 1]) ++left;
          }
        }
      }
    }
    return allRes;
  }
};
