/*
Given two arrays, write a function to compute their intersection.

  Example:
  Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
*/
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1;
    vector<int> res;
    for (int num : nums1) {
      set1.insert(num);
    }
    for (int num : nums2) {
      if (set1.count(num) > 0) {
	res.push_back(num);
	set1.erase(num); //!!! erase the num in set, otherwise duplicate
      }
    }
    return res;
  }
};
