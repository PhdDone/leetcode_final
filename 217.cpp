/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/
//use hashset, not map

//http://blog.csdn.net/zzc8265020/article/details/46358507

//or sort

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> numsSet; //use set instead of map
    for (auto num : nums) {
      if (numsSet.find(num) != numsSet.end()) return true; //use find to check
      else
	numsSet.insert(num);
    }
    return false;
  }
};
