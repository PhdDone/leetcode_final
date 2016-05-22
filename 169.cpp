/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/



class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int count = 0;
    int maj = nums[0];
    for (int num : nums) {
      if (count == 0) {
	maj = num;
	++count; //remember to add 1 here
      }
      else {
	if (num == maj) ++count;
	else --count;
      }
    }
    return maj;
  }
};
