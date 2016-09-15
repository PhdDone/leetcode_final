class RandomizedSet {
  unordered_map<int, int> mp;
  vector<int> values;
public:
  /** Initialize your data structure here. */
  RandomizedSet() {

  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (mp.count(val) != 0) return false;
    values.push_back(val);
    mp[val] = values.size() - 1;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if (mp.count(val) == 0) return false;
    int index = mp[val];
    int last_index = values.size() - 1;
    int last_value = values[last_index];
    values[index] = last_value;
    mp[last_value] = index;
    values.pop_back();
    mp.erase(val); //Remove both value and it's index!!!
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    return values[rand() % values.size()];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
