class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int curZero;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
	curZero = i;
	for (int j = curZero + 1; j < nums.size(); j++) {
	  if (nums[j] != 0) {
	    swap(nums[i], nums[j]);
	    break;
	  }
	}
      }
    }
  }
};

//2nd

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int end = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
	nums[end++] = nums[i];
      }
    }
    for (int i = end; i < nums.size(); ++i) {
      nums[i] = 0;
    }
  }
};
