/*Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

  For example,
  MovingAverage m = new MovingAverage(3);
m.next(1) = 1
  m.next(10) = (1 + 10) / 2
  m.next(3) = (1 + 10 + 3) / 3
  m.next(5) = (10 + 3 + 5) / 3
Show Company Tags
Show Tags

*/

class MovingAverage {
public:
  deque<int> q;
  int max_size;
  /** Initialize your data structure here. */
  MovingAverage(int size) {
    max_size = size;
  }
    
  double next(int val) {
    q.push_back(val);
    if (q.size() <= max_size) {
      int sum = accumulate(q.begin(), q.end(), 0);
      return sum * 1.0 / q.size();
    }
    else {
      q.pop_front();
      int sum = accumulate(q.begin(), q.end(), 0);
      return sum * 1.0 / q.size();
    }
  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
