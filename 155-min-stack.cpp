/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
*/
class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {
        
  }
    
  void push(int x) {
    StackValue.push(x);
    if (StackMin.empty()) StackMin.push(x);
    else {
      int curMin = StackMin.top();
      if (x < curMin) {
	StackMin.push(x);
      }
      else {
	StackMin.push(curMin);
      }
    }
  }
    
  void pop() {
    StackValue.pop();
    StackMin.pop();
  }
    
  int top() {
    return StackValue.top();
  }
    
  int getMin() {
    return StackMin.top();
  }
private:
  stack<int> StackValue;
  stack<int> StackMin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
