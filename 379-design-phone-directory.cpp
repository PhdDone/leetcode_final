/*
Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();




// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);

*/

//http://www.cnblogs.com/grandyang/p/5735205.html

//trick: the most recent released one should be returned first!!!!

//TLE
class PhoneDirectory {
public:
  /** Initialize your data structure here
      @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
  PhoneDirectory(int maxNumbers) {
    max_num = maxNumbers;
    next = idx = 0;
    recycle.resize(max_num);
    flag.resize(max_num, 1);
  }

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    if (next == max_num && idx <= 0) return -1;
    if (idx > 0) {
      int t = recycle[--idx];
      flag[t] = 0;
      return t;
    }
    flag[next] = false;
    return next++;
  }

  /** Check if a number is available or not. */
  bool check(int number) {
    return number >= 0 && number < max_num && flag[number];
  }

  /** Recycle or release a number. */
  void release(int number) {
    if (number >= 0 && number < max_num && !flag[number]) {
      recycle[idx++] = number;
      flag[number] = 1;
    }
  }
private:
  int max_num, next, idx;
  vector<int> recycle, flag;
};





// naive solution
class PhoneDirectory {
public:
  /** Initialize your data structure here
      @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
  PhoneDirectory(int maxNumbers) {
    numbers_.resize(maxNumbers);
    for (int i = 0; i < maxNumbers; ++i) {
      numbers_[i] = i;
    }
    next_av_ = 0;
  }

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    int res = numbers_[next_av_];
    if (used_.count(res) == 1) {
      int new_av = next_av_;
      new_av = (new_av + 1) % numbers_.size();
      while (new_av != next_av_) {
        if (used_.count(numbers_[new_av]) == 0) {
          res = numbers_[new_av];
          used_.insert(res);
          next_av_ = (new_av + 1) % numbers_.size();
          break;
        } else {
          new_av = (new_av + 1) % numbers_.size();
        }
      }
      if (new_av == next_av_) return -1;
    } else {
      next_av_ = (next_av_ + 1) % numbers_.size();
      used_.insert(res);
      return res;
    }
    return res;
  }

  /** Check if a number is available or not. */
  bool check(int number) {
    return used_.count(number) == 0;
  }

  /** Recycle or release a number. */
  void release(int number) {
    used_.erase(number);
  }
  unordered_set<int> used_;
  vector<int> numbers_;
  int next_av_;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */


//accepted
class PhoneDirectory {
public:
  /** Initialize your data structure here
      @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
  PhoneDirectory(int maxNumbers) {
    numbers_.resize(maxNumbers);
    used_.resize(maxNumbers, false);
    for (int i = 0; i < maxNumbers; ++i) {
      numbers_[i] = i;
    }
    next_av_ = 0;
  }

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    if (next_av_ == numbers_.size() && recycled.empty()) {
      return -1;
    } else {
      int res = 0;
      if (next_av_ < numbers_.size()) {
        res = numbers_[next_av_++];
      } else {
        res = recycled.top();
        recycled.pop();
      }
      used_[res] = true;
      return res;
    }
  }

  /** Check if a number is available or not. */
  bool check(int number) {
    return number >= 0 && number <= used_.size() && used_[number] == false;
  }

  /** Recycle or release a number. */
  void release(int number) {
    if (number >= 0 && number <= used_.size() && used_[number]) { //!!! check the whether we need to release it !!
      used_[number] = false;
      recycled.push(number);
    }
  }
  stack<int> recycled;
  vector<bool> used_;
  vector<int> numbers_;
  int next_av_;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
