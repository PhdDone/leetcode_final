/*
Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().

  Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].

  Call next() gets you 1, the first element in the list.

  Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.

  You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.
*/

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

//Think of "looking ahead". You want to cache the next element.
//http://www.cnblogs.com/grandyang/p/4825068.html

class Iterator {
  struct Data;
  Data* data;
public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    flag_ = false;
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    if (flag_) return value_; //use a cache value and a flag to indicate the value in valid;
    else {
      value_ = Iterator::next();
      flag_ = true;
    }
    return value_;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    if (!flag_) return Iterator::next();
    flag_ = false; //otherwise if flag_ = true, peek already call the next for you, just return the cached value_ and set flag to be false
    return value_;
        
  }

  bool hasNext() const {
    if (flag_) return true;
    return Iterator::hasNext();
  }
private:
  bool flag_;
  int value_;
};
