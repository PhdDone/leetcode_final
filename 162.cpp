/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

  The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

  For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

Note:
Your solution should be in logarithmic complexity.
*/

//s1
class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    for (int i = 0, j = nums.size(); i < j; ++i) {
      bool isPeak = false;
      if (i == 0) {
	if (i + 1 < j) {
	  isPeak = nums[i] > nums[i+1];
	  if (isPeak) return i;
	}
	else {//only one element
	  return i;
	}
      }
      else {
	if (i == j - 1) {
	  isPeak = nums[i] > nums[i - 1];
	  if (isPeak) return i;
	}
	else {
	  isPeak = nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
	  if (isPeak) return i;
	}
      }
    }
    return 0; //?? must return
  }
};


//s2

class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    if (nums.size() == 1) {
      return 0;
    }
        
    int start = 0;
    int end = nums.size() - 1;
    int mid = (start + end) / 2;
        
    while (start < end) {
      if ((mid == 0 && nums[mid] > nums[mid + 1]) || (mid == nums.size() - 1 && nums[mid - 1] < nums[mid]))
	return mid;
      else {
	if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) { //mid + 1 is within scope because we will never go to the state where mid == len(nums) - 1 and nums[mid] is not the peak.
	  return mid;
	}
	else {
	  if (mid > 0 && nums[mid] < nums[mid - 1])
	    end = mid - 1;
	  else
	    start = mid + 1;
	}
      }
      mid = (start + end) / 2;
    }
    return mid;
  }
};
