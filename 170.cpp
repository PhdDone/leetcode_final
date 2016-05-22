

class TwoSum {
  vector<int> nums;
  unordered_map<int, int> dict;
public:

  void add(int number) {
    dict[number] = nums.size();
    nums.push_back(number);
  }

  bool find(int value) {
    for (int i = 0; i < nums.size(); i++) {
      int gap = value - nums[i];
      if (dict.find(gap) != dict.end() && i != dict[gap])
	return true;
    }
    return false;
  }
};


//Time Limit Exceeded??

class TwoSum {
public:

  // Add the number to an internal data structure.
  void add(int number) {
    count[number]++;
  }

  // Find if there exists any pair of numbers which sum is equal to the value.
  bool find(int value) {
    bool found = false;
    for (auto candidate : count) {
      auto target = value - candidate.first;
      if (target == candidate.first) {
	found = candidate.second > 1? true : false;
      }
      else {
	found = count[target] > 0? true : false;
      }
    }
    return found;
  }
  unordered_map<int, int> count;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
