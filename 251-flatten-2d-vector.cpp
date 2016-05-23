/*
Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].
*/


class Vector2D {
public:
  Vector2D(vector<vector<int>>& vec2d) {
    b = vec2d.begin();
    e = vec2d.end();
    if (b != e) {
      cur = b->begin();
    }
        
  }

  int next() {
    return *cur++;
  }

  bool hasNext() {
    while(b != e && cur == b->end()) {
      b++;
      cur = b->begin();
    }
    return b != e;
  }
private:
  vector<vector<int>>::const_iterator b, e;
  vector<int>::const_iterator cur;
    
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
