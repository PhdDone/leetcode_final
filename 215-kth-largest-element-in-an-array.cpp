//https://segmentfault.com/a/1190000003704825
/*Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

  For example,
  Given [3,2,1,5,6,4] and k = 2, return 5.
*/

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    if (k < 1 || nums.size() == 0) return 0;
        
    return quickSelect(nums, k-1, 0, nums.size() - 1);
  }
    
  int quickSelect(vector<int>& nums, int k, int start, int end) {
    int pivot = nums[(start + end)/2];
    int i = start;
    int j = end;
    while (i <= j) {
      while (i <= end && nums[i] > pivot) {
	++i;
      }
      while (j >= start && nums[j] < pivot) {
	j--;
      }
      if (i <= j) {
	swap(nums[i], nums[j]);
	i++;
	j--;
      }
    }
    if (start < j && k <= j) return quickSelect(nums, k, start, j);
    if (end > i && k >= i) return quickSelect(nums, k, i, end);
    return nums[k];
        
  }
};
