/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
*/

//https://asanchina.wordpress.com/2015/12/29/323-number-of-connected-components-in-an-undirected-graph/

// Union(x, y): put x and y into same set
// Find(x): find the parent of x

class Solution {
public:
  int countComponents(int n, vector<pair<int, int>>& edges) {
    int count = n;
    root = vector<int>(n, -1);
        
    for (auto edge : edges) {
      int x = edge.first;
      int y = edge.second;
      int x_root = findRoot(x);
      int y_root= findRoot(y);
      if (x_root != y_root) {
	count--;
	unionSet(x_root, y_root);
      }
    }
    return count;
  }
    
  int findRoot(int x) {
    if (root[x] == -1) return x; //root == -1 means the real root
    return findRoot(root[x]);
  }
    
  void unionSet(int x, int y) {
    root[x] = y;
  }
  vector<int> root;
};
