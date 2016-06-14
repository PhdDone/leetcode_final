/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

  For example:

  Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

  Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
*/
class Solution {
public:
  bool validTree(int n, vector<pair<int, int>>& edges) {
    vector<int> root(n, -1);
    for(int i = 0; i < edges.size(); i++) {
      int root1 = find(root, edges[i].first);
      int root2 = find(root, edges[i].second);
      if(root1 == root2)
	return false;
      root[root1] = root2; //updating the root is enough, not the edges
    }
    return edges.size() == n - 1;
  }
    
  int find(vector<int> &root, int e) {
    if(root[e] == -1)
      return e;
    return find(root, root[e]);
  }
};
