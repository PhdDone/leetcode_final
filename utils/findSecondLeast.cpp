#include <iostream>
#include <unordered_map>

struct Node {
  int val;
  int freq = 0;
  Node(int v, int f) : val(x), freq(f) {};
};

struct cmp {
  bool operator() (Node x, Node y) {
    return x.freq < y.freq;
  }
};

int main() {
  vector<int> values = {1, 2, 3,1,33,3,,5,3,2,2,6,7,8,2,1};
  
  for (auto v : values) {
    
}

