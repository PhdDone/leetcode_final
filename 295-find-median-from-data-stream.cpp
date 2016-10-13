/*Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

  Examples:
  [2,3,4] , the median is 3

    [2,3], the median is (2 + 3) / 2 = 2.5

    Design a data structure that supports the following two operations:

  void addNum(int num) - Add a integer number from the data stream to the data structure.
    double findMedian() - Return the median of all elements so far.
    For example:

  add(1)
  add(2)
  findMedian() -> 1.5
  add(3)
  findMedian() -> 2
  */



class MedianFinder {
public:

  // Adds a number into the data structure.
  void addNum(int num) {
    if (minHeap.empty() || num > minHeap.top()) {
      minHeap.push(num);
      if (minHeap.size() - maxHeap.size() > 1) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }
    } else {
      if (maxHeap.empty() || num < maxHeap.top()) {
        maxHeap.push(num);
        if (maxHeap.size() - minHeap.size() > 1) {
          minHeap.push(maxHeap.top());
          maxHeap.pop();
        }
      } else {
        if (maxHeap.size() <= minHeap.size()) {
          maxHeap.push(num);
        } else {
          minHeap.push(num);
        }
      }
    }
  }

  // Returns the median of current data stream
  double findMedian() {
    if (maxHeap.size() > minHeap.size()) {
      return maxHeap.top();
    } else {
      if (maxHeap.size() < minHeap.size()) {
        return minHeap.top();
      } else { //!! consider in the middle !!
        if (maxHeap.empty() && minHeap.empty()) {
          return 0;
        } else {
          return (minHeap.top() + maxHeap.top()) / 2.0;
        }
      }
    }
  }
  priority_queue<int, vector<int>, std::greater<int>> minHeap;
  priority_queue<int> maxHeap;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
