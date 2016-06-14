/*For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
  The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

  You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

  Example 1:

  Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
  return [1]
*/

//https://leetcode.com/discuss/103757/my-simple-c-solution
/*
delete the node with 1 indegree

 */
class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<int> leaves;
    if(edges.size()==0 && n==0)return leaves;
    if(edges.size()==0 && n!=0)return {0};
        
    vector<vector<int>> children(n, vector<int>{});
    for (auto const& edge : edges) {
      children[edge.first].push_back(edge.second);
      children[edge.second].push_back(edge.first);
    }
        
    for (int i = 0; i < children.size(); ++i) {
      if (children[i].size() == 1) leaves.push_back(i);
    }
        
    while (n > 2) { //do it util n = 2 or 1, maybe two left, maybe one left
      vector<int> tmpLeaves;
      n = n - leaves.size();
      /*
            for (auto const& leave : leaves) {
                for (int i = 0; i < children.size(); ++i) {
                    auto child = children[i];
                    child.erase(find(child.begin(), child.end(), leave)); //delete every leave as a child
                    if (child.size() == 1) tmpLeaves.push_back(i);
                }
		}*/
      //should use the neighbor of leaves to update;
      for (auto const& leave : leaves) {
	for (auto neighbor : children[leave]) {
	  children[neighbor].erase(find(children[neighbor].begin(), children[neighbor].end(), leave));
	  if (children[neighbor].size() == 1) tmpLeaves.push_back(neighbor);
	}
      }
      leaves = tmpLeaves;
    }
    return leaves;
  }
};
