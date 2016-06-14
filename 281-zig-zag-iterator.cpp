/*
Given two 1d vectors, implement an iterator to return their elements alternately.

  For example, given two 1d vectors:

  v1 = [1, 2]
  v2 = [3, 4, 5, 6]
  By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

  Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
*/



class ZigzagIterator {
public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) : v0(v1), v1(v2), N0(v1.size()), N1(v2.size()){
    c0 = 0;
    c1 = 0;
    cv = 0;
  }

  int next() {
    if(hasNext()) {
      if (cv == 0) {
	if (c0 < N0) {
	  cv = (cv + 1) % 2;
	  return v0[c0++];
	} else { //move to c2
	  cv = (cv + 1) % 2;
	  return v1[c1++];
	}
      }
      else { //cv == 1
	if (c1 < N1) {
	  cv = (cv + 1) % 2;
	  return v1[c1++];
	} else { //c2 is full
	  cv = (cv + 1) % 2; //mv to c1
	  return v0[c0++];
	}
      }
    } else {
      return -1;
    }
  }

  bool hasNext() {
    return (c1 < N1) || (c0 < N0);   
  }
private:
  int c0; //index for v1
  int c1; //index for v2 
  int cv; //index for current vector (0 or 1)
  int N0; //size of v1
  int N1; //size of v2
  vector<int> v0;
  vector<int> v1;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
